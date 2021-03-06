{ Parsed from Webkit.framework WebResource.h }

{$ifdef TYPES}
{$ifndef WEBRESOURCE_PAS_T}
{$define WEBRESOURCE_PAS_T}

{$endif}
{$endif}

{$ifdef RECORDS}
{$ifndef WEBRESOURCE_PAS_R}
{$define WEBRESOURCE_PAS_R}

{$endif}
{$endif}

{$ifdef FUNCTIONS}
{$ifndef WEBRESOURCE_PAS_F}
{$define WEBRESOURCE_PAS_F}

{$endif}
{$endif}

{$ifdef EXTERNAL_SYMBOLS}
{$ifndef WEBRESOURCE_PAS_S}
{$define WEBRESOURCE_PAS_S}

{$endif}
{$endif}

{$ifdef FORWARD}
  WebResource = objcclass;
  WebResourcePointer = ^WebResource;
  WebResourcePtr = WebResourcePointer;

{$endif}

{$ifdef CLASSES}
{$ifndef WEBRESOURCE_PAS_C}
{$define WEBRESOURCE_PAS_C}

{ WebResource }
  WebResource = objcclass external (NSObject, NSCodingProtocol, NSCopyingProtocol)
  private
    _private: WebResourcePrivate;
    
  public
    function initWithData_URL_MIMEType_textEncodingName_frameName(data_: NSData; URL_: NSURL; MIMEType_: NSString; textEncodingName_: NSString; frameName_: NSString): id; message 'initWithData:URL:MIMEType:textEncodingName:frameName:';
    function data: NSData; message 'data';
    function URL: NSURL; message 'URL';
    function MIMEType: NSString; message 'MIMEType';
    function textEncodingName: NSString; message 'textEncodingName';
    function frameName: NSString; message 'frameName';

    { Adopted Protocols }
    procedure encodeWithCoder(aCoder: NSCoder);
    function initWithCoder(aDecoder: NSCoder): id;
    function copyWithZone(zone_: NSZonePtr): id;
  end;

{$endif}
{$endif}
