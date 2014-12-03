//
//  MADRotationView.h
//  MADNET iOS SDK -> http://help.madnet.ru
//
//  Copyright 2014 MADNET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MADSize.h"
#import "IMADRotationViewDelegate.h"
#import "IMADBaseProtocol.h"

/**
 Animation to change ad.
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
 An ad with fixed size.
 */
@interface MADRotationView : UIView<IMADBaseProtocol>
{
  @private
    id <IMADRotationViewDelegate> m_delegate;
    
  @protected
    NSUInteger m_currentTransitionStyle;
}
/**
 Animation to change ad property.
 Example:
 transitionMask = etoAnimationOptionTransitionRevealFromLeft | etoAnimationOptionTransitionRevealFromRight
 */
@property (nonatomic, assign) NSUInteger transitionMask;

@property (nonatomic, assign) id <IMADRotationViewDelegate> delegate;

@property (nonatomic, assign, readonly) BOOL isBusy;

@property (nonatomic, copy) NSString *spaceId;

@property (nonatomic, assign) CGPoint origin;


- (id) initWithAdSize: (MADSize) aAdSize;
- (id) initWithAdSize: (MADSize) aAdSize spaceId: (NSString *) aSpaceId;
- (id) initAndLoadWithAdSize: (MADSize) aAdSize
                     spaceId: (NSString *) aSpaceId
                    delegate: (id<IMADRotationViewDelegate>) aDelegate;


- (void) load;
- (void) loadWithExternalValues: (MADExternalValuesForTargeting *) aExternalValues;

- (void) invalidate; // !!!

- (BOOL) pause;
- (BOOL) play;

@end