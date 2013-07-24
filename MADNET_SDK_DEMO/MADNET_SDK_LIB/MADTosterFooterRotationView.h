//
//  MADTosterFooterRotationView.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MADTosterRotationView.h"
@interface MADTosterFooterRotationView : UIView
/**
 Создает UIView - footer Table View с баннером
 */
+ (MADTosterFooterRotationView *) footerViewForTableView: (UITableView *) aTableView
                                        withRotationView: (MADTosterRotationView *) aTosterView;

/**
 Возвращает высоту баннера
 */
+ (CGFloat) footerViewHeightWithRotationView: (MADTosterRotationView *) aTosterView;
@end
