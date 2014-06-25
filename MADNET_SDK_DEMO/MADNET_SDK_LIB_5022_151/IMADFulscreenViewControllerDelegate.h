//
//  CMADInterstitialAdManager.h
//  MADNET iOS SDK -> http://help.madnet.ru
//
//  Copyright 2014 MADNET. All rights reserved.
//


#import <Foundation/Foundation.h>

@class CMADInterstitialAdManager;

@protocol IMADFulscreenViewControllerDelegate <NSObject>

@required
- (void) fullscreenMADViewControllerDidReceiveAd: (CMADInterstitialAdManager *) aInterstitialAdManager;

@optional
- (void) fullscreenMADViewController: (CMADInterstitialAdManager *) aInterstitialAdManager didFailToReceiveAdWithError: (NSError *) aError;
- (void) fullscreenMADViewControllerWillPresentModal: (CMADInterstitialAdManager *) aInterstitialAdManager;
- (void) fullscreenMADViewControllerWillDismiss: (CMADInterstitialAdManager *) aInterstitialAdManager;
- (void) fullscreenMADViewControllerDidDismiss: (CMADInterstitialAdManager *) aInterstitialAdManager;
- (void) fullscreenMADViewControllerDidClick: (CMADInterstitialAdManager *)  aInterstitialAdManager;
- (void) fullscreenMADViewControllerDidExtraAction: (CMADInterstitialAdManager *)  aInterstitialAdManager;
- (void) fullscreenMADViewControllerWillLeaveApplication: (CMADInterstitialAdManager *)aInterstitialAdManager;
- (BOOL) fullscreenMADViewTestingMode: (CMADInterstitialAdManager *) aInterstitialAdManager;

@end
