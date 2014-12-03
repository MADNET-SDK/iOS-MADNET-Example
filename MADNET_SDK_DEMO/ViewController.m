//
//  ViewController.m
//  MADNET_SDK_DEMO
//
//  Created by AndreyIvanov on 23.07.13.
//  Copyright (c) 2013 AndreyIvanov. All rights reserved.
//

#import "ViewController.h"
#import "CMADInterstitialAdManager.h"

@interface ViewController ()<IMADFulscreenViewControllerDelegate>
{
    CMADInterstitialAdManager *_fullscreenAd;
}
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    if ([self respondsToSelector:@selector(setEdgesForExtendedLayout:)])
    {
        [self setEdgesForExtendedLayout:UIRectEdgeNone];
    }
#warning Replace SPACE_ID with you MADNET placement id
    _fullscreenAd = [[CMADInterstitialAdManager alloc] initWithSpaceId: SPACE_ID];
    _fullscreenAd.delegate = self;
    _fullscreenAd.supportRotation = YES;
}

-(IBAction) loadFullscreenAd: (id) sender
{
    [_fullscreenAd load];
}

-(IBAction) openMADNETWebSite: (id)sender
{
    [[UIApplication sharedApplication] openURL: [NSURL URLWithString:@"http://www.madnet.ru"]];
}

-(void) dealloc
{
    [_fullscreenAd invalidate]; [_fullscreenAd release];
    [super dealloc];
}

- (void) fullscreenMADViewControllerDidReceiveAd: (CMADInterstitialAdManager *) aInterstitialAdManager
{
    [aInterstitialAdManager presentFullscreenAdFromRootViewController:self];
}

- (BOOL) fullscreenMADViewTestingMode: (CMADInterstitialAdManager *) aRotationView
{
#warning Return YES value for testing purpose
    return (TESTMODE);
}

@end
