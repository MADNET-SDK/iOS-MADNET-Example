//
//  CSimpleViewController.m
//  MADNET_SDK_DEMO
//
//  Created by AndreyIvanov on 23.07.13.
//  Copyright (c) 2013 AndreyIvanov. All rights reserved.
//

#import "CSimpleViewController.h"
#import "MADRotationView.h"

@interface CSimpleViewController ()<IMADRotationViewDelegate>
{
  @private
    MADRotationView *_madnetView;
    
}
@end

@implementation CSimpleViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (UIViewController *) MADViewController
{
    return (self);
}

- (BOOL) rotationViewTestingMode: (MADRotationView *)aRotationView
{
#warning Return YES value for testing purpose
    return (TESTMODE);
}

- (void) loadView
{
    [super loadView];
    
#warning Replace SPACE_ID with you MADNET placement id
    _madnetView = [[MADRotationView alloc] initWithAdSize: kmAdSize_320x50
                                                  spaceId: SPACE_ID];
    
    _madnetView.origin = CGPointMake(0.0f, 40.0f);
    _madnetView.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin;
    [_madnetView setTranslatesAutoresizingMaskIntoConstraints:NO];
    _madnetView.transitionMask = etoAnimationOptionTransitionFlipFromLeft | etoAnimationOptionTransitionRevealFromBottom;
    
    _madnetView.delegate = self;
    [self.view addSubview: _madnetView];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    if ([self respondsToSelector:@selector(setEdgesForExtendedLayout:)])
    {
        [self setEdgesForExtendedLayout:UIRectEdgeNone];
    }
    
	// Do any additional setup after loading the view.
    
    MADExternalValuesForTargeting *values = [[MADExternalValuesForTargeting alloc] init];
    [values setValue: [CMADTargetParameters params].gender.male];
    [values setValue: [CMADTargetParameters params].education.university];
    [values setValue: [CMADTargetParameters params].income.from15to24];
    
    values.dob = [NSDate date];
    values.age = [NSNumber numberWithUnsignedInt: 18];
    
    [_madnetView loadWithExternalValues: values];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
	return YES;
}

- (BOOL) shouldAutorotate
{
    return YES;
}

- (void) dealloc
{
    [_madnetView invalidate];
    [_madnetView release]; _madnetView = nil;
    
    [super dealloc];
}

@end
