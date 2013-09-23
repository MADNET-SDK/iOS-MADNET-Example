//
//  ViewController.m
//  MADNET_SDK_DEMO
//
//  Created by AndreyIvanov on 23.07.13.
//  Copyright (c) 2013 AndreyIvanov. All rights reserved.
//

#import "ViewController.h"
#import "MADFullscreenViewController.h"

@interface ViewController ()<IMADFulscreenViewControllerDelegate>
{
    MADFullscreenViewController *_fullscreenAd;
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
    
	// Do any additional setup after loading the view, typically from a nib.
    
    _fullscreenAd = [[MADFullscreenViewController alloc] initWithSpaceId: @"150"
                                                               partnerId: nil];
    _fullscreenAd.delegate = self;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
	return (toInterfaceOrientation == UIInterfaceOrientationPortrait);
}

- (BOOL) shouldAutorotate
{
    return NO;
}

-(NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskPortrait;
}

- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation
{
	return UIInterfaceOrientationPortrait;
}

-(IBAction) loadFullscreenAd: (id) sender
{
    [_fullscreenAd load];
}

- (void) fullscreenMADViewController: (MADFullscreenViewController *) aMADViewController didFailToReceiveAdWithError: (NSError *) aError
{
    NSLog(@"%@",aError);
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
@end
