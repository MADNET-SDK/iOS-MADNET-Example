//
//  CTableFloatingADViewController.m
//  MADNET_SDK_DEMO
//
//  Created by AndreyIvanov on 24.07.13.
//  Copyright (c) 2013 AndreyIvanov. All rights reserved.
//

#import "CTableFloatingADViewController.h"
#import "MADTosterRotationView.h"

@interface CTableFloatingADViewController ()<IMADTosterRotationViewDelegate>
{
    MADTosterRotationView *_tosterAdView;
}
@end

@implementation CTableFloatingADViewController

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

    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
    
#warning Replace SPACE_ID with you MADNET placement id
    _tosterAdView = [[MADTosterRotationView alloc] initWithAdSize: kmAdSize_320x50
                                                           spaceId: SPACE_ID];
    _tosterAdView.useTosterCloseButton = YES;
    
    _tosterAdView.delegate = self;

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    return 20;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];
    [cell.textLabel setText:[NSString stringWithFormat: @"Simple Test Cell %d", indexPath.row]];
    // Configure the cell...
    
    return cell;
}


- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section
{
    [_tosterAdView load];
    return ([MADTosterRotationView footerViewForTableView: tableView
                                         withRotationView: _tosterAdView]);
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    return ([MADTosterRotationView footerViewHeightWithRotationView:_tosterAdView]);
}

- (void) scrollViewWillBeginDragging:(UIScrollView *)scrollView
{
    [_tosterAdView pauseAndHide];
}

- (void) scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate
{
    if (!decelerate)
    {
        [_tosterAdView playAndShow];
    }
}

- (void) scrollViewDidEndDecelerating:(UIScrollView *)scrollView
{
    [_tosterAdView playAndShow];
}

- (BOOL) rotationViewTestingMode: (MADRotationView *)aRotationView
{
#warning Return YES value for testing purpose
    return (TESTMODE);
}

- (UIViewController *) MADViewController
{
    return (self);
}

- (BOOL) tosterAdViewWillClose: (MADTosterRotationView *) aTosterAdView
{
    UIAlertView * alert = [[UIAlertView alloc] initWithTitle: @"Покупка"
                                                     message: @"Для того чтобы удалить баннер необходимо его купить"
                                                    delegate: self
                                           cancelButtonTitle: @"Cancel"
                                           otherButtonTitles: @"Покупка", nil];
    [alert show];
    [alert release];
    
    return (NO);
}

- (void)alertView: (UIAlertView *)alertView clickedButtonAtIndex: (NSInteger)buttonIndex
{
    switch (buttonIndex)
    {
        case 0:
            break;
        case 1:
            [_tosterAdView pauseAndHide];
            [_tosterAdView performSelector:@selector(open) withObject:nil afterDelay:20.0f];
        default:
            break;
    }
}

- (void) tosterAdViewDidClose: (MADTosterRotationView *) aTosterAdView
{
    NSLog(@"BannerSampleTableViewController::tosterAdViewDidClose");
    [_tosterAdView performSelector:@selector(open) withObject:nil afterDelay:10.0f];
}


/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    }   
    else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Navigation logic may go here. Create and push another view controller.
    /*
     <#DetailViewController#> *detailViewController = [[<#DetailViewController#> alloc] initWithNibName:@"<#Nib name#>" bundle:nil];
     // ...
     // Pass the selected object to the new view controller.
     [self.navigationController pushViewController:detailViewController animated:YES];
     [detailViewController release];
     */
}

- (void) dealloc
{
    [_tosterAdView invalidate]; [_tosterAdView release]; _tosterAdView = nil;
    [super dealloc];
}

@end
