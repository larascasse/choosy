
#import <Foundation/Foundation.h>
#import "MTLModel.h"
#import "MTLJSONAdapter.h"

@class ChoosyAppInfo;

@interface ChoosyAppType : MTLModel <MTLJSONSerializing>

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *key;
@property (nonatomic, strong) NSArray *parameters;
@property (nonatomic, strong) NSArray *actions;
@property (nonatomic, strong) NSArray *apps;

// Date the app type was last udpated from the server. If more than X hours old,
// the object is considered invalid and only used if data cannot be retrieved from server
@property (nonatomic, strong) NSDate *dateUpdated;

/**
 *  Call this once the type is instantiated, including a list of apps, to grab latest data, etc.
 */
- (void)update;

/**
 *  Check which apps that belong to this app type, if any, are installed on the device.
 *
 *  @return Array of ChoosyAppInfo objects representing installed apps, or nil if none are installed.
 */
- (NSArray *)installedApps;
- (NSArray *)newApps;
- (ChoosyAppInfo *)defaultApp;

+ (ChoosyAppType *)filterAppTypesArray:(NSArray *)appTypes byKey:(NSString *)appTypeKey;
- (ChoosyAppInfo *)findAppInfoWithAppKey:(NSString *)appKey;

@end
