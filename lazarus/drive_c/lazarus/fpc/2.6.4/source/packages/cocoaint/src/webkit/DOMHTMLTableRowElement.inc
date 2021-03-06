{ Parsed from Webkit.framework DOMHTMLTableRowElement.h }

{$ifdef TYPES}
{$ifndef DOMHTMLTABLEROWELEMENT_PAS_T}
{$define DOMHTMLTABLEROWELEMENT_PAS_T}

{$endif}
{$endif}

{$ifdef RECORDS}
{$ifndef DOMHTMLTABLEROWELEMENT_PAS_R}
{$define DOMHTMLTABLEROWELEMENT_PAS_R}

{$endif}
{$endif}

{$ifdef FUNCTIONS}
{$ifndef DOMHTMLTABLEROWELEMENT_PAS_F}
{$define DOMHTMLTABLEROWELEMENT_PAS_F}

{$endif}
{$endif}

{$ifdef EXTERNAL_SYMBOLS}
{$ifndef DOMHTMLTABLEROWELEMENT_PAS_S}
{$define DOMHTMLTABLEROWELEMENT_PAS_S}

{$endif}
{$endif}

{$ifdef FORWARD}
  DOMHTMLTableRowElement = objcclass;
  DOMHTMLTableRowElementPointer = ^DOMHTMLTableRowElement;
  DOMHTMLTableRowElementPtr = DOMHTMLTableRowElementPointer;

{$endif}

{$ifdef CLASSES}
{$ifndef DOMHTMLTABLEROWELEMENT_PAS_C}
{$define DOMHTMLTABLEROWELEMENT_PAS_C}

{ DOMHTMLTableRowElement }
  DOMHTMLTableRowElement = objcclass external (DOMHTMLElement)
    
  public
    function rowIndex: cint; message 'rowIndex';
    function sectionRowIndex: cint; message 'sectionRowIndex';
    function cells: DOMHTMLCollection; message 'cells';
    procedure setAlign (newValue: NSString); message 'setAlign:';
    function align: NSString; message 'align';
    procedure setBgColor (newValue: NSString); message 'setBgColor:';
    function bgColor: NSString; message 'bgColor';
    procedure setCh (newValue: NSString); message 'setCh:';
    function ch: NSString; message 'ch';
    procedure setChOff (newValue: NSString); message 'setChOff:';
    function chOff: NSString; message 'chOff';
    procedure setVAlign (newValue: NSString); message 'setVAlign:';
    function vAlign: NSString; message 'vAlign';
    function insertCell(index: cint): DOMHTMLElement; message 'insertCell:';
    procedure deleteCell(index: cint); message 'deleteCell:';
  end;

{$endif}
{$endif}
