//
//  IMADBaseProtocol.h
//  MADNET iOS SDK -> http://help.madnet.ru
//
//  Copyright 2014 MADNET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "MADExternalValuesForTargeting.h"

typedef enum EMADStateEnum
{
	emsMADStateHidden = -1,
	emsMADStateDefault = 0,
	emsMADStateResized = 1,
	emsMADStateExpanded = 2
} MADState;

/**
 Basic protocol for ad formats.
 */
@protocol IMADBaseProtocol <NSObject>

@required

/**
 Start loading ads with default settings.
 */
- (void) load;

/**
 Start loading ads with external settings.
 @param aExternalValues расширенные параметры для таргетирования
 */
- (void) loadWithExternalValues: (MADExternalValuesForTargeting *) aExternalValues;

/**
 MADNET space identifier.
 */
@property (nonatomic, copy) NSString *spaceId;

/**
 If YES - allows automatically collect geo data..
 */
@property (nonatomic, assign) BOOL allowLocation;

@property (nonatomic, retain, readonly) NSError *lastError;
@property (nonatomic, assign, readonly) MADState currentState;

@end
