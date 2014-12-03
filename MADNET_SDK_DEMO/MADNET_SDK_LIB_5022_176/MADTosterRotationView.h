//
//  MADTosterRotationView.h
//  MADNET iOS SDK -> http://help.madnet.ru
//
//  Copyright 2014 MADNET. All rights reserved.
//

#import "MADRotationView.h"
#import "IMADTosterRotationViewDelegate.h"

@interface MADTosterRotationView : MADRotationView
{
  @protected
    BOOL m_withFooterView;
    BOOL m_isClose;
    BOOL m_isPlay;
    BOOL m_isPause;
}

@property (nonatomic, assign) BOOL isPause;
@property (nonatomic, assign) BOOL isPlay;
@property (nonatomic, assign) BOOL isClose;

@property (nonatomic, assign) id<IMADTosterRotationViewDelegate> delegate;
@property (nonatomic, assign) BOOL useTosterCloseButton; // default value YES
@property (nonatomic, assign, readonly) BOOL withFooterView;

/**
 @return Returns an object - table footer with ad.
 */
+ (UIView *) footerViewForTableView: (UITableView *) aTableView
                   withRotationView: (MADTosterRotationView *) aTosterView;
/**
 @@return footer height.
 */
+ (CGFloat) footerViewHeightWithRotationView: (MADTosterRotationView *) aTosterView;

/**
 Allows you to reload the ad after the user has closed using a native close button.
 */
- (BOOL) open;

- (BOOL) pauseAndHide;
- (BOOL) playAndShow;

@end