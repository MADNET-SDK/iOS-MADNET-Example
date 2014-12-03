//
//  CTableADViewController.m
//  MADNET_SDK_DEMO
//
//  Created by AndreyIvanov on 23.07.13.
//  Copyright (c) 2013 AndreyIvanov. All rights reserved.
//

#import "CMADTableSimpleAdViewController.h"
#import "CMADTableViewAdCell.h"

@interface CMADTableSimpleAdViewController ()<IMADRotationViewDelegate>
{
    NSUInteger _adstep;
    NSMutableArray *_madnetcells;
}
@end

@implementation CMADTableSimpleAdViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    if ([self respondsToSelector:@selector(setEdgesForExtendedLayout:)])
    {
        [self setEdgesForExtendedLayout:UIRectEdgeNone];
    }
    
    _adstep = 5;
    _madnetcells = [[NSMutableArray alloc] init];
}

- (BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
	return YES;
}

-(BOOL)shouldAutorotate
{
    return YES;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return (1);
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return (30);
}

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ((indexPath.row + 1) % _adstep <= 0)
    {
        [(CMADTableViewAdCell*)cell loadMADContentWithDelegate: self];
    }
}

- (CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ((indexPath.row + 1) % _adstep == 0)
    {
        return (50.0f);
    }
    else
    {
        return (30.0f);
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{    
    UITableViewCell *cell = nil;
    if ((indexPath.row + 1) % _adstep <= 0)
    {
        static NSString *kMADNETCellIdentifier = @"kMADNETCellIdentifier";
        cell = [tableView dequeueReusableCellWithIdentifier: kMADNETCellIdentifier];
        if (![_madnetcells containsObject: cell]) [_madnetcells addObject: cell];
        
    }
    else
    {
        static NSString *kCellIdentifier = @"Cell";
        cell = [tableView dequeueReusableCellWithIdentifier:kCellIdentifier forIndexPath:indexPath];
        [cell.textLabel setText:[NSString stringWithFormat: @"Simple Test Cell %ld", (long)indexPath.row]];
    }

    return cell;
}

- (BOOL) rotationViewTestingMode: (MADRotationView *)aRotationView
{
#warning change to NO before deploy to AppStore
    return (TESTMODE);
}

- (UIViewController *) MADViewController
{
    return (self);
}

- (void) invalidate
{
    for (CMADTableViewAdCell *madnetcell in _madnetcells)
    {
        [madnetcell invalidate];
    }
    [_madnetcells removeAllObjects];
}

- (void) dealloc
{
    [self invalidate];
    [_madnetcells release];
    [super dealloc];
}

@end
