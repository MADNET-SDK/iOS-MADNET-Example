//
//  CMADVASTADManager.h
//  MADNET_SDK
//
//  Created by Andrey Ivanov on 01.12.14.
//
//

#import <Foundation/Foundation.h>
#import "IMADVASTADManagerDelegate.h"
#import "MADExternalValuesForTargeting.h"

@interface CMADVASTADManager : NSObject
@property (nonatomic, assign) id<IMADVASTADManagerDelegate> delegate;
- (void) play;
@property (nonatomic, copy) NSString *spaceId;
- (void) load;
- (void) loadWithExternalValues: (MADExternalValuesForTargeting *) aExternalValues;

- (void) invalidate;
@end