//
//  MADTableViewCell.h
//  admee
//
//  Created by a.ivanov on 15.11.12.
//  Copyright (c) 2012 a.ivanov. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MADRotationView.h"
#import "IMADRotationViewDelegate.h"

@interface MADTableViewCell : UITableViewCell

- (void) loadMADContentWithDelegate: (id<IMADRotationViewDelegate>) aDelegate;
- (void) invalidate;

@end
