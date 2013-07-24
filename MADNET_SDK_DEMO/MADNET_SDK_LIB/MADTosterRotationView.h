//
//  MADTosterRotationView.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
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
 Создает UIView - footer Table View с баннером
 */
+ (UIView *) footerViewForTableView: (UITableView *) aTableView
                   withRotationView: (MADTosterRotationView *) aTosterView;
/**
 Возвращает высоту баннера
 */
+ (CGFloat) footerViewHeightWithRotationView: (MADTosterRotationView *) aTosterView;

/**
 Позволяет заново открыть баннер, после того, как пользователь его закрыл 
 с использованием нативной кнопки.
 */
- (BOOL) open;

/**
 Позволяет приостановить загрузку и показ контейнера.
 */
- (BOOL) pauseAndHide;

/**
 Позволяет возобновить загрузку и показ контейнера.
 */
- (BOOL) playAndShow;

@end