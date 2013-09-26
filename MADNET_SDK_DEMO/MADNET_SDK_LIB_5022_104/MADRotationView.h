//
//  MADRotationView.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MADSize.h"
#import "IMADRotationViewDelegate.h"
#import "IMADBaseProtocol.h"

/**
 Перечисление доступных анимация для ротации баннеров.
 */

typedef NS_OPTIONS(NSUInteger, EmAdTransitionAnimationOption)
{
    etoOptionTransitionNone                      = 1 << 0, //UIViewAnimationOptionTransitionNone,
    etoAnimationOptionTransitionFlipFromLeft     = 1 << 1, //UIViewAnimationOptionTransitionFlipFromLeft,
    etoAnimationOptionTransitionFlipFromRight    = 1 << 2, //UIViewAnimationOptionTransitionFlipFromRight,
    etoAnimationOptionTransitionCurlUp           = 1 << 3, //UIViewAnimationOptionTransitionCurlUp,
    etoAnimationOptionTransitionCurlDown         = 1 << 4, //UIViewAnimationOptionTransitionCurlDown,
    etoAnimationOptionTransitionCrossDissolve    = 1 << 5, //UIViewAnimationOptionTransitionCrossDissolve,
    etoAnimationOptionTransitionFlipFromTop      = 1 << 6, //UIViewAnimationOptionTransitionFlipFromTop,
    etoAnimationOptionTransitionFlipFromBottom   = 1 << 7, //UIViewAnimationOptionTransitionFlipFromBottom,
	etoAnimationOptionTransitionRevealFromRight  = 1 << 8,
	etoAnimationOptionTransitionRevealFromLeft   = 1 << 9,
	etoAnimationOptionTransitionRevealFromTop    = 1 << 10,
	etoAnimationOptionTransitionRevealFromBottom = 1 << 11
};

/**
 Контейнер для отображения баннеров фиксированного размера 
 */
@interface MADRotationView : UIView<IMADBaseProtocol>
{
  @private
    id <IMADRotationViewDelegate> m_delegate;
    
  @protected
    NSUInteger m_currentTransitionStyle;
}
/**
 Маска для задания возможных видов анимаций при смене баннеров. По умолчанию
 transitionMask = etoAnimationOptionTransitionRevealFromLeft | etoAnimationOptionTransitionRevealFromRight
 */
@property (nonatomic, assign) NSUInteger transitionMask;

@property (nonatomic, assign) id <IMADRotationViewDelegate> delegate;
/**
 Описание последней ошибки возникшей
 */
@property (nonatomic, retain, readonly) NSError *lastError;
/**
 Текущее состояние ORMMA баннера
 */
@property (nonatomic, assign, readonly) MADState currentState;

@property (nonatomic, assign, readonly) BOOL isBusy;

@property (nonatomic, copy) NSString *spaceId;
@property (nonatomic, copy) NSString *partnerId;
@property (nonatomic, assign) CGPoint origin;

@property (nonatomic, assign) BOOL allowLocation;

/**
 Конструктор инициализации для задания размера контейнеру
 */
- (id) initWithAdSize: (MADSize) aAdSize;

/**
 Конструктор инициализации.
 @param aAdSize - размер контейнера.
 @param aSpaceId - spaceId контейнера.
 @param aPartnerId - partnerId контейнера.
 */
- (id) initWithAdSize: (MADSize) aAdSize spaceId: (NSString *) aSpaceId partnerId: (NSString *) aPartnerId;

/**
 Конструктор инициализации для задания размера контейнеру с последующим стартом загрузки.
 При инициализации контейнера данным методом вызывать метод play не следует.
 */
- (id) initAndLoadWithAdSize: (MADSize) aAdSize
                     spaceId: (NSString *) aSpaceId
                   partnerId: (NSString *) aPartnerId
                    delegate: (id<IMADRotationViewDelegate>) aDelegate;

/**
 Метод вызывается для начала ротации баннеров в контейнере
 */
- (void) load;

/**
 Метод, разрушающий контейнер - необходимо вызывать при разрушении
 родительской вьюхи
 */
- (void) invalidate;

- (void) loadWithExternalValues: (MADExternalValuesForTargeting *) aExternalValues;

- (void) loadWithBase: (MADBaseRequestParametrs *) aBaseValues
			 external: (MADExternalValuesForTargeting *) aExternalValues;

- (BOOL) pause;
- (BOOL) play;

@end