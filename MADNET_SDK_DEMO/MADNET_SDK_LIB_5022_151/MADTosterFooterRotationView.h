//
//  MADTosterFooterRotationView.h
//  MADNET iOS SDK -> http://help.madnet.ru
//
//  Copyright 2014 MADNET. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MADTosterRotationView.h"

@interface MADTosterFooterRotationView : UIView
/**
 @return Returns an object - table footer with ad.
 */
+ (MADTosterFooterRotationView *) footerViewForTableView: (UITableView *) aTableView
                                        withRotationView: (MADTosterRotationView *) aTosterView;

/**
 @return footer height.
 */
+ (CGFloat) footerViewHeightWithRotationView: (MADTosterRotationView *) aTosterView;
@end
