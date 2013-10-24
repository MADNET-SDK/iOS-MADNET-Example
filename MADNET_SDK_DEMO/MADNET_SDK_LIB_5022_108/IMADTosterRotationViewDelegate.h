//
//  IMADTosterRotationViewDelegate.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "IMADRotationViewDelegate.h"
@class MADTosterRotationView;
@protocol IMADTosterRotationViewDelegate <IMADRotationViewDelegate>
@optional
/**
 Метод вызывается в случае, если пользователь нажал на кретик баннера.
 Возвращая NO можно запретить пользователю закрывать баннер или
 попросить его сделать дополнительную покупку для удаления баннера.
 */
- (BOOL) tosterAdViewWillClose: (MADTosterRotationView *) aTosterAdView;
/**
 Метод вызывается когда баннер уже удален.
 */
- (void) tosterAdViewDidClose: (MADTosterRotationView *) aTosterAdView;
@end
