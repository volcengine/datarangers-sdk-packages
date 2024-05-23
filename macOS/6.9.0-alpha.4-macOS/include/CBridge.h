//
//  CBridge.h
//  RangersAppLog
//
//  Created by 朱元清 on 2021/6/10.
//

#ifndef RAL_CBridge_h
#define RAL_CBridge_h

/// Start RangersAppLog based on some configuation parameters.
/// @param appID appID
/// @param channel channel
/// @param enable_encrypt whether enable paylod encrypt. Note: enable it in production is strongly recommanded.
/// @param enable_log whether enable Logging
/// @param host server host for privatization deployment, e.g.: https://awesomeapp.com/ Pass `NULL` to ignore this.
void ral_start(const char *appID, const char *channel, bool enable_ab, bool enable_encrypt, bool enable_log, const char *host);


/* User */
void ral_set_user_unique_id(const char *user_unique_id);

void ral_clear_user_unique_id(void);

char *ral_get_user_unique_id(void);


/* Track */
void ral_track(const char *event, const char *params);

/* Profile */
void ral_profile_set(const char *properties);

void ral_profile_set_once(const char *properties);

void ral_profile_unset(const char *prop_name);

void ral_profile_append(const char *properties);

void ral_profile_increment(const char *properties);


/* Flush */
void ral_flush(void);


/* Custom Header */
void ral_set_custom_header_with_dictionary(const char *dictJSON);

void ral_set_custom_header_value_for_key(const char *key, const char *val);

void ral_remove_custom_header(const char *key);


/* AB Test */
/// get exposured Vids
char* ral_get_ab_sdk_version(void);

char* ral_get_ab_sdk_version_sync(void);

char* ral_get_all_ab_test_config(void);

char* ral_get_all_ab_test_config_sync(void);

char* ral_get_all_ab_test_config2(void);

char* ral_ab_test_config_value_for_key(const char *key);

char* ral_ab_test_config_value_sync_for_key(const char *key);

void ral_ab_set_external_ab_versions(const char *external_ab_versions);


/* Various IDs */
char* ral_device_id(void);

char* ral_ssid(void);

char* ral_install_id(void);

char* ral_appid(void);

#endif /* CBridge_h */
