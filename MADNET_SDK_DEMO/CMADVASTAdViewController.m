//
//  CMADVASTAdViewController.m
//  MADNET_SDK_DEMO
//
//  Created by Andrey Ivanov on 02.12.14.
//  Copyright (c) 2014 AndreyIvanov. All rights reserved.
//

#import "CMADVASTAdViewController.h"
#import "IMADVASTADManagerDelegate.h"
#import "CMADVASTADManager.h"

@interface CMADVASTAdViewController ()<IMADVASTADManagerDelegate>
@property (nonatomic, retain) CMADVASTADManager *manager;
@end

@implementation CMADVASTAdViewController

- (void) viewDidLoad
{
    [super viewDidLoad];
    self.manager = [[[CMADVASTADManager alloc] init] autorelease];
#warning replace SPACE_ID with you MADNET placement id
    self.manager.spaceId = SPACE_ID;
    self.manager.delegate = self;
}

- (IBAction) loadVASTAd: (id)sender
{
    [self.manager load];
}

- (UIViewController *) viewControllerForVASTPlayer
{
    return (self);
}

- (void) madnetVastReady: (CMADVASTADManager *) aVastManager
{
    [aVastManager play];
}

- (void) madnetVastTrackingEvent: (NSString *) aVastEventString
{
    NSLog(@"MADNET: tracking vast event %@", aVastEventString);
}

- (void) madnetVastError: (NSString *) aVastErrorDescription
{
    NSLog(@"MADNET: tracking error event %@", aVastErrorDescription);
}

- (void) dealloc
{
    [self.manager invalidate];
    self.manager = nil;
    [super dealloc];
}
@end