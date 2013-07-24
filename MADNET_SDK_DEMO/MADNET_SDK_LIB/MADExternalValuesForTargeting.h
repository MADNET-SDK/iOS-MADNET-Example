//
//  MADExternalValuesForTargeting.h
//  Part of MADNET iOS SDK -> http://madnet.ru
//
//  Created by Andrey Ivanov.
//  Copyright 2013 TinkoffDigital. All rights reserved.
//  Copyright 2013 MADNET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CoreLocation/CoreLocation.h"


@class MADExternalValuesForTargeting;
typedef id (^CExternalValueSettingBlock)(MADExternalValuesForTargeting *);

/**
 Класс, инкапсулирующий параметры для таргетирования, настраиваемые паблишером
 */
@interface MADExternalValuesForTargeting : NSObject
{
@private
    NSString *m_category_Primary;
	NSString *m_category_Secondary;
	NSMutableSet *m_keywords;

	NSNumber *m_age;
	NSDate *m_dob;
	NSString *m_gen;
	NSString *m_income;
	NSString *m_ethnicity;
	NSString *m_education;
	NSString *m_genderSought;
	NSString *m_maritalStatus;
	NSMutableSet *m_qs;

	NSString *m_city;
	NSString *m_gps;
	NSString *m_region;
	NSString *m_zip;

	NSString *m_areaCode;
}

/** Первичная категория приложения */
@property (nonatomic, copy) NSString * category_Primary;
/** Вторичная категория приложения */
@property (nonatomic, copy) NSString * category_Secondary;
/** Множество ключевых слов */
@property (nonatomic, retain) NSMutableSet * keywords;
/** Возраст */
@property (nonatomic, retain) NSNumber *age;
/** Дата рождения */
@property (nonatomic, retain) NSDate *dob;
/** Пол */
@property (nonatomic, copy) NSString *gen;
/** Доход */
@property (nonatomic, copy) NSString * income;
/** Этническая принадлежность */
@property (nonatomic, copy) NSString * ethnicity;
/** Образование */
@property (nonatomic, copy) NSString * education;
/** Предпочтения */
@property (nonatomic, copy) NSString * genderSought;
/** Семейное положение */
@property (nonatomic, copy) NSString * maritalStatus;
/** Слова, искомые в браузере */
@property (nonatomic, retain) NSMutableSet * qs;
/** Город */
@property (nonatomic, copy) NSString * city;
/** GPS Координаты в формате 37.530676,-122.262447 */
@property (nonatomic, copy) NSString * gps;
/** Регион или штат */
@property (nonatomic, copy) NSString * region;
/** Почтовый индекс */
@property (nonatomic, copy) NSString * zip;
/** Код Location Area Code */
@property (nonatomic, copy) NSString * areaCode;

/**
 Метод устанавливает значение свойства объекта класса
 @param aValue - блок, определяющий новое значение свойства
 */
- (void) setValue:(CExternalValueSettingBlock)aValue;

@end

/** Класс, содержащий возможные значения для пола */
@interface Gender : NSObject
@property (nonatomic, readonly, copy) CExternalValueSettingBlock male;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock female;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock unknown;
@end

/** Класс, содержащий возможные значения для дохода */
@interface Income : NSObject
@property (nonatomic, readonly, copy) CExternalValueSettingBlock lessThan15;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock from15to24;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock from25to39;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock from40to59;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock from60to74;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock from75to99;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock moreThan100;
@end

/** Класс, содержащий возможные значения для этнической принадлежности */
@interface Ethnicity : NSObject
@property (nonatomic, readonly, copy) CExternalValueSettingBlock white;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock middleeastern;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock black;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock latino;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock southasian;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock oriental;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock other;
@end

/** Класс, содержащий возможные значения для образования */
@interface Education : NSObject
@property (nonatomic, readonly, retain) CExternalValueSettingBlock lessThenSecondary;
@property (nonatomic, readonly, retain) CExternalValueSettingBlock secondary;
@property (nonatomic, readonly, retain) CExternalValueSettingBlock university;
@property (nonatomic, readonly, retain) CExternalValueSettingBlock advanced;
@end

/** Класс, содержащий возможные значения для предпочтений */
@interface Gendersought : NSObject
@property (nonatomic, readonly, copy) CExternalValueSettingBlock male;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock female;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock both;
@end

/** Класс, содержащий возможные значения для семейного положения */
@interface MaritalStatus : NSObject
@property (nonatomic, readonly, copy) CExternalValueSettingBlock single;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock married;
@property (nonatomic, readonly, copy) CExternalValueSettingBlock divorced;
@end

/**
 Класс, инкапсулирующий блоки таргетируемых параметров
 */
@interface CmAdTargetParameters : NSObject
{
	Gender *m_gender;
	Income *m_income;
	Ethnicity *m_ethnicity;
	Education *m_education;
	Gendersought *m_gendersought;
	MaritalStatus *m_maritalStatus;
}

@property (nonatomic, readonly, retain) Gender * gender;
@property (nonatomic, readonly, retain) Income * income;
@property (nonatomic, readonly, retain) Ethnicity * ethnicity;
@property (nonatomic, readonly, retain) Education * education;
@property (nonatomic, readonly, retain) Gendersought *gendersought;
@property (nonatomic, readonly, retain) MaritalStatus *maritalStatus;

/** Статический конструктор */
+ (CmAdTargetParameters *) params;

@end
