//
//  MADFullscreenViewController.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "IMADFulscreenViewControllerDelegate.h"
#import "IMADBaseProtocol.h"

/**
 Класс интерститиал-контейнера
 */
@interface MADFullscreenViewController : UIViewController <IMADBaseProtocol>
{
@private
    UIViewController<IMADFulscreenViewControllerDelegate> *m_delegate;
	BOOL m_supportRotation;
}

/**
 Конструктор инициализации.
 @param aSpaceId - spaceId контейнера.
 @param aPartnerId - partnerId контейнера.
 */
- (id) initWithSpaceId: (NSString *) aSpaceId partnerId: (NSString *) aPartnerId;

/**
 Метод необходимо вызвать ПЕРЕД удалением контейнера
 */
- (void) invalidate;

/** 
 Делегат fullscreen-контейнера 
 */
@property (nonatomic, assign) UIViewController<IMADFulscreenViewControllerDelegate> *delegate;

/** 
 Свойство, определяющее поддержку смены ориентации контейнера 
 */
@property (nonatomic, assign) BOOL supportRotation;

/** 
 SpaceId
 */
@property (nonatomic, copy) NSString *spaceId;

/**
 PartnerId
 */
@property (nonatomic, copy) NSString *partnerId;

@property (nonatomic, assign) BOOL allowLocation;

@property (nonatomic, assign) NSTimeInterval delayForCloseButtonShow;

@end
