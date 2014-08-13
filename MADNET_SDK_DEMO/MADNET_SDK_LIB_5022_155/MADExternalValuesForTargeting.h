//
//  MADExternalValuesForTargeting.h
//  MADNET iOS SDK -> http://help.madnet.ru
//
//  Copyright 2014 MADNET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CoreLocation/CoreLocation.h"

@class MADExternalValuesForTargeting;
typedef id (^CExternalValueSettingBlock)(MADExternalValuesForTargeting *);

@interface MADExternalValuesForTargeting : NSObject

/** DOB */
@property (nonatomic, retain) NSDate *dob;
/** Years */
@property (nonatomic, retain) NSNumber *age;

/**
 This method sets the value of the object.
 
 Example:
 MADExternalValuesForTargeting *values = [[MADExternalValuesForTargeting alloc] init];
 [values setValue: [[CMADTargetParameters params].keywords addKeywords: @[@"keyword1", @"keyword2"]]];
 [values setValue: [CMADTargetParameters params].gender.male];
 [values setValue: [CMADTargetParameters params].income.from75to99];
 [values setValue: [CMADTargetParameters params].ethnicity.white];
 [values setValue: [CMADTargetParameters params].education.advanced];
 [values setValue: [CMADTargetParameters params].gendersought.both];
 [values setValue: [CMADTargetParameters params].maritalStatus.single];
 [values setDob: [NSDate date]];
 [values setAge: @25];
 */
- (void) setValue:(CExternalValueSettingBlock)aValue;

@end

@interface CMADKeywords : NSObject
- (CExternalValueSettingBlock) addKeyword: (NSString *) aKeyword;
- (CExternalValueSettingBlock) addKeywords: (NSArray *) aKeywords;
@end

@interface CMADLocation : NSObject
- (CExternalValueSettingBlock) addLocationWithLat: (CLLocationDegrees) aUserLatitude
                                           andLon: (CLLocationDegrees) aUserLongitude;
@end

@interface CMADGender : NSObject
@property (nonatomic, readonly, copy) CExternalValueSettingBlock male;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock female;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock unknown;
@end

/**
 Income in thousands of dollars.
 Example: lessThan15 - less than 15 000$.
 */
@interface CMADIncome : NSObject
@property (nonatomic, readonly, copy) CExternalValueSettingBlock lessThan15;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock from15to24;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock from25to39;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock from40to59;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock from60to74;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock from75to99;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock moreThan100;
@end

@interface CMADEthnicity : NSObject
@property (nonatomic, readonly, copy) CExternalValueSettingBlock white;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock middleeastern;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock black;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock latino;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock southasian;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock oriental;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock other;
@end

@interface CMADEducation : NSObject
@property (nonatomic, readonly, retain) CExternalValueSettingBlock lessThenSecondary;
@property (nonatomic, readonly, retain) CExternalValueSettingBlock secondary;
@property (nonatomic, readonly, retain) CExternalValueSettingBlock university;
@property (nonatomic, readonly, retain) CExternalValueSettingBlock advanced;
@end

@interface CMADGendersought : NSObject
@property (nonatomic, readonly, copy) CExternalValueSettingBlock male;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock female;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock both;
@end

@interface CMADMaritalStatus : NSObject
@property (nonatomic, readonly, copy) CExternalValueSettingBlock single;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock married;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock divorced;
@end


@interface CMADTargetParameters : NSObject
@property (nonatomic, readonly, retain) CMADGender * gender;
@property (nonatomic, readonly, retain) CMADIncome * income;
@property (nonatomic, readonly, retain) CMADEthnicity * ethnicity;
@property (nonatomic, readonly, retain) CMADEducation * education;
@property (nonatomic, readonly, retain) CMADGendersought *gendersought;
@property (nonatomic, readonly, retain) CMADMaritalStatus *maritalStatus;
@property (nonatomic, readonly, retain) CMADLocation *location;
@property (nonatomic, readonly, retain) CMADKeywords *keywords;

+ (CMADTargetParameters *) params;
@end
