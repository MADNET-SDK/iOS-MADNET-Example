//
//  CmAdBannerEntity.h
//  ORMMA
//
//  Created by i.khokhlov on 27.09.12.
//
//

#import <Foundation/Foundation.h>

enum
{
    eatMRAID = 0,
    eatHTML = 1
}; typedef NSUInteger EApiType;

enum
{
    ectOpenUrl = 0,
    ectPlayVideo = 1,
    ectOpenMap = 2,
    ectSendMail = 3,
    ectSendSMS = 4,
    ectStorePicture = 5,
    ectInstallApp = 6,
    ectCreateEvent = 7,
    ectMakeCall = 8,
    ectPlayAudio = 9,
    ectUndefined = 10
}; typedef NSUInteger EActionType;

@interface CmAdBannerEntity : NSObject
{
@private
	EApiType m_apiType;
	NSString *m_source;
    BOOL _innerOpen;
}

@property (nonatomic, assign) EApiType apiType;
@property (nonatomic, assign) EActionType actionType;
@property (nonatomic, assign) BOOL innerOpen;

@property (nonatomic, assign) NSTimeInterval durationTime;
@property (nonatomic, copy) NSString * source;

- (id) initWithDictionary: (NSDictionary *) aDictionary;
- (instancetype) initWithSource: (NSString *) aHTMLString;
- (BOOL) openWithLeaveApplication;
- (BOOL) isValid;

@end
