//
//  CTableADViewController.m
//  MADNET_SDK_DEMO
//
//  Created by AndreyIvanov on 23.07.13.
//  Copyright (c) 2013 AndreyIvanov. All rights reserved.
//

#import "CTableADViewController.h"
#import "MADTableViewCell.h"

@interface CTableADViewController ()<IMADRotationViewDelegate>
{
    NSUInteger _adstep;
}
@end

@implementation CTableADViewController

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
    
    _adstep = 5;

    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
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
        [(MADTableViewCell*)cell loadMADContentWithDelegate: self];
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
    }
    else
    {
        static NSString *kCellIdentifier = @"Cell";
        cell = [tableView dequeueReusableCellWithIdentifier:kCellIdentifier forIndexPath:indexPath];
        [cell.textLabel setText:[NSString stringWithFormat: @"Simple Test Cell %d", indexPath.row]];
    }

    return cell;
}

- (UIViewController *) MADViewController
{
    return (self);
}

@end
