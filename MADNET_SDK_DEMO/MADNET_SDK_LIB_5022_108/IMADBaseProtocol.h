//
//  IMADBaseProtocol.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "MADBaseRequestParametrs.h"
#import "MADExternalValuesForTargeting.h"

typedef enum EMADStateEnum
{
	emsMADStateHidden = -1,
	emsMADStateDefault = 0,
	emsMADStateResized = 1,
	emsMADStateExpanded = 2
} MADState;

/**
 Протокол делегата view баннера
 */
@protocol IMADBaseProtocol <NSObject>

@required

@property (nonatomic, retain, readonly) NSError *lastError;

/**
 Текущее состояние view
 */
@property (nonatomic, assign, readonly) MADState currentState;

@property (nonatomic, copy) NSString *spaceId;

/**
 В случае, если установлен в YES - используется внутренний браузер
 и переход по ссылке осуществляется без выхода из приложения.
 По умолчанию - NO.
 */
@property (nonatomic, assign) BOOL useInternalBrowser;

/**
 В случае если установленв в  YES разрешает контейнеру автоматически собирать и
 отправлять информацию о местоположении.
 */
@property (nonatomic, assign) BOOL allowLocation;

/**
 Метод начала загрузки баннеров с параметрами по умолчанию
 */
- (void) load;

/**
 Метод начала загрузки баннеров с расширенными параметрами
 @param aExternalValues расширенные параметры для таргетирования
 */
- (void) loadWithExternalValues: (MADExternalValuesForTargeting *) aExternalValues;

/**
 Метод начала загрузки баннеров с базовыми и расширенными параметрами
 @param aBaseValues базовые параметры для таргетирования
 @param aExternalValues расширенные параметры для таргетирования
 */
- (void) loadWithBase: (MADBaseRequestParametrs *) aBaseValues
			 external: (MADExternalValuesForTargeting *) aExternalValues;

@end
