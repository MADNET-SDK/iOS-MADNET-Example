//
//  MADFullscreenViewController.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
//


#import <Foundation/Foundation.h>

@class MADFullscreenViewController;

@protocol IMADFulscreenViewControllerDelegate <NSObject>
@optional

- (void) fullscreenMADViewController: (MADFullscreenViewController *) aMADViewController didFailToReceiveAdWithError: (NSError *) aError;
- (void) fullscreenMADViewControllerWillPresentModal: (MADFullscreenViewController *) aMADViewController;
- (void) fullscreenMADViewControllerWillDismiss: (MADFullscreenViewController *) aMADViewController;
- (void) fullscreenMADViewControllerDidDismiss: (MADFullscreenViewController *) aMADViewController;
- (void) fullscreenMADViewControllerDidClick: (MADFullscreenViewController *)  aMADViewController;
- (void) fullscreenMADViewControllerDidExtraAction: (MADFullscreenViewController *)  aMADViewController;
- (void) fullscreenMADViewControllerWillLeaveApplication: (MADFullscreenViewController *)aMADViewController;

@end
