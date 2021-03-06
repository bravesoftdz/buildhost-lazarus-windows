
{ Parse category/protocol symbols from NSObject.h }
{-parse NSObject.h}

{ This unit adds categories and protocols to NSObject in objcbase.pp }
{ //include NSObjectSupport.inc} 

{ === From OS 10.5 === }
{$include NSObjCRuntime.inc} 
{$include NSInvocation.inc}
{$include NSPointerFunctions.inc}
{$include NSAffineTransform.inc} 
{$include NSArray.inc} 
{$include NSAttributedString.inc}
{$include NSAutoreleasePool.inc} 
{$include NSBundle.inc} 
{$include NSCalendar.inc} 
{$include NSCharacterSet.inc} 
{$include NSClassDescription.inc} 
{$include NSCoder.inc} 
{$include NSArchiver.inc} 
{$include NSConnection.inc} 
{$include NSData.inc} 
{$include NSDate.inc} 
{$include NSCalendarDate.inc} 
{$include NSDecimal.inc} 
{$include NSDictionary.inc} 
{$include NSDistributedLock.inc} 
{$include NSEnumerator.inc} 
{$include NSError.inc} 
{$include NSException.inc} 
{$include NSFileHandle.inc} 
{$include NSFileManager.inc} 
{$include NSFormatter.inc} 
{$include NSDateFormatter.inc}
{$include NSGarbageCollector.inc} 
{$include NSSet.inc} 
{$include NSScanner.inc} 
{$include NSValue.inc} 
{$include NSDecimalNumber.inc}
{$include NSValueTransformer.inc} 
{$include NSGeometry.inc} 
{$include NSHashTable.inc} 
{$include NSHFSFileTypes.inc} 
{$include NSHost.inc} 
{$include NSIndexPath.inc} 
{$include NSIndexSet.inc} 
{$include NSKeyValueCoding.inc} 
{$include NSKeyValueObserving.inc} 
{$include NSKeyedArchiver.inc} 
{$include NSLocale.inc} 
{$include NSLock.inc} 
{$include NSMapTable.inc} 
{$include NSMetadata.inc} 
{$include NSMethodSignature.inc} 
{$include NSNetServices.inc} 
{$include NSNotification.inc} 
{$include NSNotificationQueue.inc} 
{$include NSDistributedNotificationCenter.inc} 
{$include NSNull.inc} 
{$include NSNumberFormatter.inc} 
{$include NSOperation.inc} 
{$include NSPointerArray.inc} 
{$include NSPort.inc} 
{$include NSPortCoder.inc} 
{$include NSPortMessage.inc} 
{$include NSPortNameServer.inc} 
{$include NSProcessInfo.inc} 
{$include NSPropertyList.inc} 
{$include NSProxy.inc} 
{$include NSProtocolChecker.inc} 
{$include NSDistantObject.inc} 
{$include NSRange.inc} 
{$include NSRunLoop.inc} 
{$include NSSortDescriptor.inc} 
{$include NSSpellServer.inc} 
{$include NSStream.inc} 
{$include NSString.inc} 
{$include NSPathUtilities.inc} 
{$include NSTask.inc} 
{$include NSThread.inc} 
{$include NSTimeZone.inc} 
{$include NSTimer.inc} 
{$include NSUndoManager.inc} 
{$include NSURL.inc} 
{$include NSURLHandle.inc} 
{$include NSUserDefaults.inc} 
{$include NSXMLNode.inc} 
{$include NSXMLDTD.inc} 
{$include NSXMLDTDNode.inc} 
{$include NSXMLDocument.inc} 
{$include NSXMLElement.inc} 
{$include NSXMLNodeOptions.inc} 
{$include NSXMLParser.inc} 
{ include NSZone.inc} 
{$include NSExpression.inc} 
{$include NSPredicate.inc} 
{$include NSComparisonPredicate.inc} 
{$include NSCompoundPredicate.inc} 
{$include NSAppleEventDescriptor.inc} 
{$include NSAppleEventManager.inc} 
{$include NSAppleScript.inc} 
{$include NSObjectScripting.inc} 
{$include NSScriptClassDescription.inc} 
{$include NSScriptCoercionHandler.inc} 
{$include NSScriptCommand.inc} 
{$include NSScriptCommandDescription.inc} 
{$include NSScriptExecutionContext.inc} 
{$include NSScriptKeyValueCoding.inc} 
{$include NSScriptObjectSpecifiers.inc} 
{$include NSScriptStandardSuiteCommands.inc} 
{$include NSScriptSuiteRegistry.inc} 
{$include NSScriptWhoseTests.inc} 
{$include NSURLAuthenticationChallenge.inc} 
{$include NSURLCredential.inc} 
{$include NSURLCredentialStorage.inc} 
{$include NSURLProtectionSpace.inc} 
{$include NSURLCache.inc} 
{$include NSURLConnection.inc} 
{$include NSURLProtocol.inc} 
{$include NSURLRequest.inc} 
{$include NSURLResponse.inc} 
{$include NSHTTPCookie.inc} 
{$include NSHTTPCookieStorage.inc} 
{$include NSURLDownload.inc} 
{$include NSURLError.inc} 

{ === From OS 10.6 === }
{$include NSCache.inc}
{$include NSOrthography.inc}
{$include NSTextCheckingResult.inc}
