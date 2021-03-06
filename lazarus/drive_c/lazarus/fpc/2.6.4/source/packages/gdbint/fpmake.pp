{$ifndef ALLPACKAGES}
{$mode objfpc}{$H+}
program fpmake;

uses fpmkunit, classes, sysutils;

{$endif ALLPACKAGES}

const
  GdbLibName = 'libgdb.a';
  MinGWGdbLibName = 'libmingw32.a';

procedure BeforeCompile_gdbint(Sender: TObject);
var
  L : TStrings;
  P : TPackage;
  GdbLibDir, GdbLibFile: string;
  GdbLibFound: boolean;
  GdbVerTarget: TTarget;
  HostOS: TOS;
  HostCPU: TCpu;
begin
  P := Sender as TPackage;
  HostOS:=StringToOS({$I %FPCTARGETOS%});
  HostCPU:=StringToCPU({$I %FPCTARGETCPU%});
  // Search for a libgdb file.
  GdbLibFound:=false;

  // First try the environment setting GDBLIBDIR
  GdbLibDir := GetEnvironmentVariable('GDBLIBDIR');
  if (GdbLibDir<>'') and DirectoryExists(GdbLibDir) then
    begin
      GdbLibFile:=IncludeTrailingPathDelimiter(GdbLibDir)+GdbLibName;
      if not FileExists(GdbLibFile) then
        Installer.BuildEngine.Log(vlCommand,'GDBLIBDIR environment variable set, but libgdb not found. ('+GdbLibFile+')')
      else
        GdbLibFound:=true;
    end;

  // Try the default locations
  if not GdbLibFound then
    begin
      GdbLibDir:='..'+PathDelim+'..'+PathDelim+'libgdb';
      if DirectoryExists(GdbLibDir) then
        begin
          GdbLibDir:=GdbLibDir+PathDelim+OSToString(Defaults.OS);
          GdbLibFile:=GdbLibDir+PathDelim+GdbLibName;
          if FileExists(GdbLibFile) then
            GdbLibFound:=true
          else
            begin
              GdbLibDir:=GdbLibDir+PathDelim+CPUToString(Defaults.CPU);
              GdbLibFile:=GdbLibDir+PathDelim+GdbLibName;
              GdbLibFound:=FileExists(GdbLibFile);
            end;
        end;
    end;

  // When we're cross-compiling, running the gdbver executable to detect the
  // gdb-version is not possible, unless a i386-win32 to i386-go32v2 compilation
  // is performed.
  if GdbLibFound and
     (((Defaults.CPU=HostCPU) and (Defaults.OS=HostOS))
       or ((Defaults.CPU=i386) and (Defaults.OS=go32v2) and (HostOS=win32) and (HostCPU=i386))) then
    begin
      P.Options.Add('-Fl'+GdbLibDir);
      GdbVerTarget:=p.Targets.AddUnit('src'+PathDelim+'gdbver.pp');
      Installer.BuildEngine.ResolveFileNames(p,HostCPU,HostOS,false);
      Installer.BuildEngine.Log(vlCommand,'GDB-lib found, compiling and running gdbver to obtain GDB-version');
      Installer.BuildEngine.Compile(P,GdbVerTarget);
      p.Targets.Delete(GdbVerTarget.Index);
      Installer.BuildEngine.ExecuteCommand('src/gdbver','-o src/gdbver.inc');

      // Pass -dUSE_MINGW_GDB to the compiler when a MinGW gdb is used
      if FileExists(GdbLibDir+PathDelim+MinGWGdbLibName) then
        begin
          P.Options.Add('-dUSE_MINGW_GDB');
          Installer.BuildEngine.Log(vlCommand,'Using GDB (MinGW)')
        end
      else
        begin
          Installer.BuildEngine.Log(vlCommand,'Using GDB')
        end;
    end
  else
    begin
      // No suitable gdb found, use gdb_nogdb.inc
      L := TStringList.Create;
      try
        if P.Directory<>'' then
          L.values['src'+DirectorySeparator+'gdbver_nogdb.inc'] := IncludeTrailingPathDelimiter(P.Directory) +'src'+DirectorySeparator+'gdbver.inc'
        else
          L.values['src'+DirectorySeparator+'gdbver_nogdb.inc'] := 'src'+DirectorySeparator+'gdbver.inc';
        Installer.BuildEngine.cmdcopyfiles(L, Installer.BuildEngine.StartDir);
      finally
        L.Free;
      end;

    end;
end;

procedure AfterCompile_gdbint(Sender: TObject);
var
  L : TStrings;
begin
  // Remove the generated gdbver.inc
  L := TStringList.Create;
  try
    L.add(IncludeTrailingPathDelimiter(Installer.BuildEngine.StartDir)+'src/gdbver.inc');
    Installer.BuildEngine.CmdDeleteFiles(L);
  finally
    L.Free;
  end;
end;

procedure add_gdbint;

Var
  P : TPackage;
  T : TTarget;
begin
  With Installer do
    begin
    P:=AddPackage('gdbint');
{$ifdef ALLPACKAGES}
    P.Directory:='gdbint';
{$endif ALLPACKAGES}
    P.Version:='2.6.4';
    P.Author := 'Library : Cygnus, header: Peter Vreman';
    P.License := 'Library: GPL2 or later, header: LGPL with modification, ';
    P.HomepageURL := 'www.freepascal.org';
    P.Email := '';
    P.Description := 'Interface to libgdb, the GDB debugger in library format';
    P.NeedLibC:= true;  // true for headers that indirectly link to libc?

    P.OSes:=[beos,haiku,freebsd,netbsd,openbsd,linux,win32,win64,go32v2];

    P.SourcePath.Add('src');
    P.IncludePath.Add('src');

    P.BeforeCompileProc:=@BeforeCompile_gdbint;
    P.AfterCompileProc:=@AfterCompile_gdbint;

    //
    // NOTE: the gdbver.inc dependancies gives warnings because the makefile.fpc
    // does a "cp src/gdbver_nogdb.inc src/gdbver.inc" to create it

    T:=P.Targets.AddUnit('gdbcon.pp');
      with T.Dependencies do
        begin
          AddUnit('gdbint');
        end;
    T:=P.Targets.AddUnit('gdbint.pp');
      with T.Dependencies do
        begin
          AddInclude('gdbver.inc');
        end;
    end;
end;

{$ifndef ALLPACKAGES}
begin
  add_gdbint;
  Installer.Run;
end.
{$endif ALLPACKAGES}

