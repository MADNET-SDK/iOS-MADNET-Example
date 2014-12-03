//
//  IMADVASTADManagerDelegate.h
//  MADNET_SDK
//
//  Created by Andrey Ivanov on 01.12.14.
//
//
#import <UIKit/UIKit.h>

@class CMADVASTADManager;

@protocol IMADVASTADManagerDelegate

@required
- (UIViewController *) viewControllerForVASTPlayer;
- (void) madnetVastReady: (CMADVASTADManager *) aVastManager;

@optional
- (void) madnetVastWillPresentFullScreen: (CMADVASTADManager *) aVastManager;
- (void) madnetVastDidDismissFullScreen: (CMADVASTADManager *) aVastManager;
- (void) madnetVastTrackingEvent: (NSString *) aVastEventString;
- (void) madnetVastError: (NSString *) aVastErrorDescription;
- (BOOL) madnetVastTestMode: (CMADVASTADManager*) aVastManager;
@end

