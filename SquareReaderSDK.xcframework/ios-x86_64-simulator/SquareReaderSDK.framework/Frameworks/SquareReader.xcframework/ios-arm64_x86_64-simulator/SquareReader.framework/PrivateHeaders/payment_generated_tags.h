// Copyright 2017 Square, Inc.
#pragma once
typedef enum 
{
    ETAG_TRANSACTION_TYPE                              = 0x9c,
    ETAG_DEFAULT_DDOL                                  = 0xdf8132,
    ETAG_RRP_GRACE_PERIOD_MIN                          = 0xdf8132,
    ETAG_DEFAULT_TDOL                                  = 0xdf8133,
    ETAG_RRP_GRACE_PERIOD_MAX                          = 0xdf8133,
    ETAG_ICC_UN                                        = 0xdf8134,
    ETAG_RRP_CAPDU_EXPECTED_TIME_TERM                  = 0xdf8134,
    ETAG_RRP_RAPDU_EXPECTED_TIME_TERM                  = 0xdf8135,
    ETAG_RRP_ACCURACY_THRESHOLD                        = 0xdf8136,
    PTAG_UNKOWNTAGS_UPDATE_CONDITION                   = 0xdf8546,
    PTAG_SUPPORTED_AID_KERNEL_ID_MAPPING               = 0xdf8547,
    ETAG_IIN                                           = 0x42,
    ETAG_AID                                           = 0x4f,
    ETAG_APP_LABEL                                     = 0x50,
    PTAG_TXRS_APP_NOTIFY_LABEL                         = 0x50,
    ETAG_TRACK1_DATA                                   = 0x56,
    ETAG_TRACK2_ED                                     = 0x57,
    ETAG_ICC_PAN_CN                                    = 0x5a,
    ETAG_CARD_HOLDER_NAME                              = 0x5f20,
    PTAG_TXRS_RESULT_CARD_INFO_NAME                    = 0x5f20,
    PTAG_5F21                                          = 0x5f21,
    ETAG_ICC_AEXPD_N                                   = 0x5f24,
    ETAG_ICC_AED_N                                     = 0x5f25,
    ETAG_ICC_ISSUER_COUNTRY_CODE_N                     = 0x5f28,
    ETAG_TRANSACTION_CURR_CODE                         = 0x5f2a,
    ETAG_LANG_PREFERENCE                               = 0x5f2d,
    PTAG_TXRS_APP_NOTIFY_LANG_PREFS                    = 0x5f2d,
    ETAG_SERVICE_CODE                                  = 0x5f30,
    ETAG_ICC_PANSN_N                                   = 0x5f34,
    ETAG_TRANSACTION_CURR_EXP                          = 0x5f36,
    ETAG_ISS_URL                                       = 0x5f50,
    ETAG_IBAN                                          = 0x5f53,
    ETAG_DEK_IDENTIFIER                                = 0x5f53,
    ETAG_BANK_IDENTIFIER_CODE                          = 0x5f54,
    ETAG_ICC_COMMON_DEBIT_COUNTRY_CODE                 = 0x5f55,
    ETAG_ICC_ISSUER_COUNTRY_CODE_ALPHA3                = 0x5f56,
    ETAG_ACCOUNT_TYPE                                  = 0x5f57,
    ETAG_APPLICATION_TEMPLATE                          = 0x61,
    ETAG_FCI                                           = 0x6f,
    ETAG_READ_RESPONSE_TEMPLATE                        = 0x70,
    ETAG_ISSUER_SCRIPT_TEMPLATE_1                      = 0x71,
    ETAG_ISSUER_SCRIPT_TEMPLATE_2                      = 0x72,
    ETAG_DIRECTORY_DISCRETIONARY_TEMPLATE              = 0x73,
    ETAG_RESPONSE_FMT_2                                = 0x77,
    ETAG_RESPONSE_FMT_1                                = 0x80,
    ETAG_AMOUNT_BIN                                    = 0x81,
    ETAG_APPLICATION_INTERCHANGE_PROFILE               = 0x82,
    ETAG_CMD_TEMPLATE                                  = 0x83,
    ETAG_DEDICATED_FILE_NAME                           = 0x84,
    PTAG_TXRS_APP_NOTIFY_ADF_NAME                      = 0x84,
    ETAG_ISSUER_SCRIPT_COMMAND                         = 0x86,
    ETAG_APPLICATION_PRIORITY_INDICATOR                = 0x87,
    ETAG_TXRS_APP_NOTIFY_PRORITY                       = 0x87,
    ETAG_SHORT_FILE_IDENTIFIER                         = 0x88,
    ETAG_AUTHORISATION_CODE                            = 0x89,
    ETAG_AUTHORISATION_RESPONSE_CODE                   = 0x8a,
    ETAG_CARD_RISK_MGMT_DOL_1                          = 0x8c,
    ETAG_CARD_RISK_MGMT_DOL_2                          = 0x8d,
    ETAG_CVM_LIST                                      = 0x8e,
    ETAG_CA_PUB_KEY_IDX_CARD                           = 0x8f,
    ETAG_ISSUER_PUB_KEY_CERT                           = 0x90,
    ETAG_ISSUER_AUTHENTICATION_DATA                    = 0x91,
    ETAG_ISSUER_PUB_REMAINDER                          = 0x92,
    ETAG_SIGNED_STATIC_APPLICATION_DATA                = 0x93,
    ETAG_APPLICATION_FILE_LOCATOR                      = 0x94,
    ETAG_TERMINAL_VERIFICATION_RESULTS                 = 0x95,
    ETAG_TRANSACTION_CERT_DATA_OBJ_LIST                = 0x97,
    ETAG_TRANSACTION_CERT_HASH_VALUE                   = 0x98,
    ETAG_TRANSACTION_PIN_DATA                          = 0x99,
    ETAG_TRANSACTION_DATE                              = 0x9a,
    ETAG_TRANSACTION_STATUS_INFORMATION                = 0x9b,
    ETAG_DIRECTORY_DEFINITION_FILE_NAME                = 0x9d,
    ETAG_ACQUIRER_IDENTIFIER                           = 0x9f01,
    ETAG_AMOUNT_AUTHORISED_NUMERIC                     = 0x9f02,
    ETAG_AMOUNT_OTHER_NUMERIC                          = 0x9f03,
    ETAG_AMOUNT_OTHER_BIN                              = 0x9f04,
    ETAG_APPLICATION_DISCRETIONARY_DATA                = 0x9f05,
    ETAG_APPLICATION_IDENTIFIER                        = 0x9f06,
    ETAG_APPLICATION_USAGE_CONTROL                     = 0x9f07,
    ETAG_APPLICATION_VERSION_NUMBER_CARD               = 0x9f08,
    ETAG_APPLICATION_VERSION_NUMBER_T                  = 0x9f09,
    ETAG_APPLICATION_PROPRIETARY_DATA                  = 0x9f0a,
    ETAG_CARDHOLDER_NAME_EXT                           = 0x9f0b,
    ETAG_IINE                                          = 0x9f0c,
    ETAG_ISSUER_ACTION_CODE_DEFAULT                    = 0x9f0d,
    ETAG_ISSUER_ACTION_CODE_DENIAL                     = 0x9f0e,
    ETAG_ISSUER_ACTION_CODE_ONLINE                     = 0x9f0f,
    ETAG_ISSUER_APPLICATION_DATA                       = 0x9f10,
    ETAG_ISSUER_CODE_TABLE_INDEX                       = 0x9f11,
    PTAG_APPLICATION_PREFERRED_NAME                    = 0x9f12,
    ETAG_LAST_ONLINE_ATC_REGISTER                      = 0x9f13,
    ETAG_LOWER_CONSECUTIVE_OFFLINE_LIMIT               = 0x9f14,
    ETAG_MERCHANT_CAT_CODE                             = 0x9f15,
    ETAG_MERCHANT_IDENTIFIER                           = 0x9f16,
    ETAG_PIN_TRY_COUNTER                               = 0x9f17,
    ETAG_ISSUER_SCRIPT_IDENTIFIER                      = 0x9f18,
    ETAG_TRID                                          = 0x9f19,
    ETAG_TERMINAL_COUNTRY_CODE                         = 0x9f1a,
    ETAG_TERMINAL_FLOOR_LIMIT                          = 0x9f1b,
    ETAG_TERMINAL_IDENTIFICATION                       = 0x9f1c,
    ETAG_TERMINAL_RISK_MANAGEMENT_DATA                 = 0x9f1d,
    ETAG_IFD_SERIAL_NUMBER                             = 0x9f1e,
    ETAG_TRACK1_DISCRETIONARY_DATA                     = 0x9f1f,
    ETAG_TRACK2_DISCRETIONARY_DATA                     = 0x9f20,
    ETAG_TRANSACTION_TIME                              = 0x9f21,
    ETAG_VAS_APPLICATION_VERSION_NUMBER_MOBILE         = 0x9f21,
    ETAG_UPPER_CONS_OFFLINE_LIMIT                      = 0x9f23,
    ETAG_VAS_MOBILE_CAPABILITIES                       = 0x9f23,
    ETAG_PAYMENT_ACCOUNT_REFERENCE                     = 0x9f24,
    ETAG_VAS_UNPREDICTABLE_NUMBER_MOBILE               = 0x9f24,
    ETAG_ICC_LAST_4_DIGITS_PAN_N                       = 0x9f25,
    ETAG_VAS_MERCHANT_LOYALTY_ID                       = 0x9f25,
    ETAG_APPLICATION_CRYPTOGRAM                        = 0x9f26,
    ETAG_VAS_TERMINAL_CAPABILITIES                     = 0x9f26,
    ETAG_CRYPTOGRAM_INFORMATION_DATA                   = 0x9f27,
    ETAG_VAS_DATA                                      = 0x9f27,
    ETAG_PE_PUB_KEY_CERT                               = 0x9f2d,
    ETAG_PE_PUB_KEY_EXP                                = 0x9f2e,
    ETAG_PE_PUB_KEY_REMAINDER                          = 0x9f2f,
    ETAG_ISSUER_PUB_EXP                                = 0x9f32,
    ETAG_TERM_CAPABILITY                               = 0x9f33,
    ETAG_CVM_RESULTS                                   = 0x9f34,
    ETAG_TERMINAL_TYPE                                 = 0x9f35,
    ETAG_APPLICATION_TRANSACTION_COUNTER               = 0x9f36,
    ETAG_UNPREDICTABLE_NUMBER                          = 0x9f37,
    ETAG_PDOL                                          = 0x9f38,
    ETAG_POS_ENTRY_MOD                                 = 0x9f39,
    ETAG_AMOUNT_REFERENCE_CURRENCY                     = 0x9f3a,
    ETAG_APP_REF_CURRENCY                              = 0x9f3b,
    ETAG_TRANSACTION_REF_CURRENCY_CODE                 = 0x9f3c,
    ETAG_TRANS_REF_CURRENCY_EXPONENT                   = 0x9f3d,
    ETAG_ADDITIONAL_TERMINAL_CAPABILITIES              = 0x9f40,
    ETAG_TRANSACTION_SEQUENCE_COUNTER                  = 0x9f41,
    ETAG_APPLICATION_CURRENCY_CODE                     = 0x9f42,
    ETAG_APPLICATION_REFCURRENCY_EXPONENT              = 0x9f43,
    ETAG_APPLICATION_CURRENCY_EXPONENT                 = 0x9f44,
    ETAG_DATA_AUTH_CODE                                = 0x9f45,
    ETAG_ICC_PUB_KEY_CERT                              = 0x9f46,
    ETAG_ICC_PUB_KEY_EXP                               = 0x9f47,
    ETAG_ICC_PUB_KEY_REMAINDER                         = 0x9f48,
    ETAG_DDOL                                          = 0x9f49,
    ETAG_STATIC_DATA_AUTH_TAG_LIST                     = 0x9f4a,
    ETAG_SDAD                                          = 0x9f4b,
    ETAG_ICC_DYNAMIC_NUMBER                            = 0x9f4c,
    ETAG_LOG_ENTRY                                     = 0x9f4d,
    ETAG_MERCHANT_NAME_LOC                             = 0x9f4e,
    PTAG_LOG_FORMAT                                    = 0x9f4f,
    ETAG_JCB_CARDHOLDER_VERIFICATION_STATUS            = 0x9f50,
    ETAG_OFFLINE_ACCUMULATOR_BAL                       = 0x9f50,
    ETAG_JCB_TERMINAL_COMPATIBILITY_INDICATOR          = 0x9f52,
    ETAG_TRANSACTION_CAT_CODE                          = 0x9f53,
    ETAG_JCB_TERMINAL_INTERCHANGE_PROFILE              = 0x9f53,
    ETAG_INTERAC_MERCHANT_TYPE_IND                     = 0x9f58,
    ETAG_INTERAC_TERMINAL_TRANSACTION_INFORMATION      = 0x9f59,
    ETAG_INTERAC_TERMINAL_TRANSACTION_TYPE             = 0x9f5a,
    ETAG_PROGRAM_ID                                    = 0x9f5a,
    ETAG_ISSUER_SCRIPT_RESULTS                         = 0x9f5b,
    ETAG_DS_DOL                                        = 0x9f5b,
    ETAG_JCB_MSD_DEFAULT_MDOL                          = 0x9f5c,
    ETAG_DS_REQ_OPERATOR_ID                            = 0x9f5c,
    ETAG_TERMINAL_CONTACTLESS_RECEIPT_REQUIRED_LIMIT   = 0x9f5d,
    ETAG_APP_CAP_INFO_ICC                              = 0x9f5d,
    ETAG_VISA_AOSA                                     = 0x9f5d,
    ETAG_TERMINAL_OPTION_STATUS                        = 0x9f5e,
    ETAG_DS_ID                                         = 0x9f5e,
    ETAG_INTERAC_TERM_OPTION_STATUS                    = 0x9f5e,
    ETAG_INTERAC_CL_FLOOR_LIMIT                        = 0x9f5f,
    ETAG_DS_SLOT_AVAILABILITY                          = 0x9f5f,
    ETAG_TERMINAL_CONTACTLESS_FLOOR_LIMIT              = 0x9f5f,
    ETAG_JCB_OFFLINE_BALANCE                           = 0x9f5f,
    ETAG_INTERAC_CARD_TRANSACTION_INFO                 = 0x9f63,
    ETAG_PUNATC_T1                                     = 0x9f63,
    ETAG_TTQ                                           = 0x9f66,
    ETAG_PUNATC_T2                                     = 0x9f66,
    ETAG_CARD_AUTHENTICATION_RELATED_DATA              = 0x9f69,
    ETAG_ICC_UDOL                                      = 0x9f69,
    ETAG_VISA_CARD                                     = 0x9f69,
    ETAG_UN_MC                                         = 0x9f6a,
    ETAG_MC_TRACK2_DATA                                = 0x9f6b,
    ETAG_CARD_TRANSACTION_QUALIFIERS                   = 0x9f6c,
    ETAG_MAG_STRIPE_APPLICATION_VERSION                = 0x9f6d,
    ETAG_AMEX_EXPRESSPAY_TERMINAL_CAPABILITIES         = 0x9f6d,
    ETAG_FORM_FACTOR_INDICATOR                         = 0x9f6e,
    ETAG_THIRD_PARTY_DATA                              = 0x9f6e,
    ETAG_AMEX_ENHANCED_CONTACTLESS_READER_CAPABILITIES = 0x9f6e,
    ETAG_VISA_FFI                                      = 0x9f6e,
    ETAG_DE_PROTECTED_DATA_ENVELOPE_1_INTERAC_FFI      = 0x9f70,
    ETAG_CARD_INTERFACE_CAPABILITIES                   = 0x9f70,
    ETAG_DE_PROTECTED_DATA_ENVELOPE_1                  = 0x9f70,
    ETAG_INTERAC_FFI                                   = 0x9f70,
    ETAG_DE_PROTECTED_DATA_ENVELOPE_2                  = 0x9f71,
    ETAG_AMEX_MOBILE_CVM_RESULT                        = 0x9f71,
    ETAG_DISCOVER_CPR                                  = 0x9f71,
    ETAG_DE_PROTECTED_DATA_ENVELOPE_3                  = 0x9f72,
    ETAG_DE_PROTECTED_DATA_ENVELOPE_4                  = 0x9f73,
    ETAG_DE_PROTECTED_DATA_ENVELOPE_5                  = 0x9f74,
    ETAG_DE_UNPROTECTED_DATA_ENVELOPE_1                = 0x9f75,
    ETAG_DE_UNPROTECTED_DATA_ENVELOPE_2                = 0x9f76,
    ETAG_DE_UNPROTECTED_DATA_ENVELOPE_3                = 0x9f77,
    ETAG_DE_UNPROTECTED_DATA_ENVELOPE_4                = 0x9f78,
    ETAG_DE_UNPROTECTED_DATA_ENVELOPE_5                = 0x9f79,
    ETAG_CUSTOMER_EXCLUSIVE_DATA                       = 0x9f7c,
    ETAG_DS_SUMMARY_1                                  = 0x9f7d,
    ETAG_DISCOVER_AVN                                  = 0x9f7d,
    ETAG_MOBILE_SUPPORT_INDICATOR                      = 0x9f7e,
    ETAG_DISCOVER_DCVV                                 = 0x9f7e,
    ETAG_DISCOVER_DCVV_9F80                            = 0x9f80,
    ETAG_FCI_PROPRIETARY_TEMPLATE                      = 0xa5,
    ETAG_FCI_ISSUER_DISCRETIONARY_DATA                 = 0xbf0c,
    ETAG_FCI_ISSUER_DATA                               = 0xbf0c,
    ETAG_DS_UPDATE_TEMPLATE                            = 0xbf10,
    PTAG_ENCIPHERED_PIN_DATA                           = 0xc0,
    PTAG_C1                                            = 0xc1,
    PTAG_AID_ACTUAL_LEN                                = 0xc1,
    PTAG_C2                                            = 0xc2,
    PTAG_KERNEL_ID                                     = 0xc2,
    PTAG_C3                                            = 0xc3,
    PTAG_C4                                            = 0xc4,
    PTAG_C5                                            = 0xc5,
    PTAG_C6                                            = 0xc6,
    PTAG_C7                                            = 0xc7,
    PTAG_D7                                            = 0xd7,
    PTAG_UIRESPONSE_ACCOUNTTYPE                        = 0xd7,
    PTAG_NDEF_OVERRIDE                                 = 0xd7,
    ETAG_P_DEFAULT_DDOL                                = 0xdf04,
    ETAG_P_DEFAULT_TDOL                                = 0xdf05,
    ETAG_TERMINAL_ACTION_CODE_DEFAULT                  = 0xdf0a,
    ETAG_TERMINAL_ACTION_CODE_DENIAL                   = 0xdf0b,
    ETAG_TERMINAL_ACTION_CODE_ONLINE                   = 0xdf0c,
    PTAG_TERM_DATA_CFG_VER                             = 0xdf21,
    PTAG_UIREQUEST_CARD_INFO_TLV                       = 0xdf21,
    PTAG_TERM_LANG_CODE                                = 0xdf22,
    PTAG_UIREQUEST_LIST_COUNT                          = 0xdf22,
    PTAG_TX_TIMEOUT                                    = 0xdf27,
    PTAG_UIREQUEST_BUZZER_LED_SEQUENCE                 = 0xdf27,
    PTAG_P_CARD_WAIT_TIMEOUT                           = 0xdf2c,
    PTAG_REVOKED_CA_PUBKEY_INDEX                       = 0xdf34,
    PTAG_REVOKED_CERT_SERIAL_NUMBER                    = 0xdf35,
    PTAG_CONFIGURATION_NUMBER                          = 0xdf37,
    ETAG_INTL_FLOOR_LIMIT                              = 0xdf45,
    ETAG_DS_INPUT_CARD                                 = 0xdf60,
    ETAG_DS_ODS_INFO                                   = 0xdf62,
    ETAG_INTERAC_APP_SELECTION_FLAG                    = 0xdf62,
    ETAG_DS_ODS_TERMINAL                               = 0xdf63,
    ETAG_BAL_READ_BEFORE_GENAC                         = 0xdf8104,
    ETAG_BAL_READ_AFTER_GENAC                          = 0xdf8105,
    ETAG_DS_AC_TYPE                                    = 0xdf8108,
    ETAG_DS_INPUT_TERMINAL                             = 0xdf8109,
    ETAG_DS_ODS_INFO_READER                            = 0xdf810a,
    ETAG_KERNEL_ID                                     = 0xdf810c,
    ETAG_DSVN_TERMINAL                                 = 0xdf810d,
    ETAG_DS_POST_GAC_PUTDATA_STATUS                    = 0xdf810e,
    ETAG_DS_PRE_GAC_PUTDATA_STATUS                     = 0xdf810f,
    ETAG_DS_PROCEED_FIRST_WRITE_FLAG                   = 0xdf8110,
    ETAG_TAGS_TO_READ                                  = 0xdf8112,
    ETAG_TERMINAL_ERROR_INDICATION                     = 0xdf8115,
    ETAG_UI_REQ_DATA                                   = 0xdf8116,
    ETAG_CARD_DATA_INPUT_CAP                           = 0xdf8117,
    ETAG_CVM_CAP_CVM_REQ                               = 0xdf8118,
    ETAG_CVM_CAP_NO_CVM_REQ                            = 0xdf8119,
    ETAG_DEFAULT_UDOL                                  = 0xdf811a,
    ETAG_CL_MC_KERNEL_CFG                              = 0xdf811b,
    ETAG_MAX_LIFETIME_TTL_RECORD                       = 0xdf811c,
    ETAG_MAX_NO_TTL_RECORD                             = 0xdf811d,
    ETAG_MSR_CVM_CAP_CVM_REQ                           = 0xdf811e,
    ETAG_SECURITY_CAP                                  = 0xdf811f,
    ETAG_TAC_DEFAULT                                   = 0xdf8120,
    ETAG_TAC_DENIAL                                    = 0xdf8121,
    ETAG_TAC_ONLINE                                    = 0xdf8122,
    ETAG_CL_FLOOR_LIMIT                                = 0xdf8123,
    ETAG_CL_TR_LIMIT_NO_ON_DEVICE_CVM                  = 0xdf8124,
    ETAG_CL_TR_LIMIT_ON_DEVICE_CVM                     = 0xdf8125,
    ETAG_READER_CVM_REQ_LIMIT                          = 0xdf8126,
    ETAG_IDS_STATUS                                    = 0xdf8128,
    ETAG_OUTCOME_PARAM_SET                             = 0xdf8129,
    ETAG_MSR_CVM_CAP_NO_CVM_REQ                        = 0xdf812c,
    ETAG_MSG_HOLD_TIME                                 = 0xdf812d,
    ETAG_CT_KERNEL_CFG                                 = 0xdf812e,
    ETAG_HOLD_TIME                                     = 0xdf8130,
    PTAG_PAYMENT_METHOD                                = 0xdf8138,
    PTAG_ACCOUNT_TYPE_LIST                             = 0xdf8139,
    PTAG_ICC_AID_LIST                                  = 0xdf8140,
    PTAG_CANDIDATE_AID_LIST                            = 0xdf8141,
    ETAG_TARGET_PERCENT_FOR_RANDOMSEL                  = 0xdf8201,
    ETAG_THRESHOLD_FOR_BIASED_RANDOMSEL                = 0xdf8202,
    ETAG_MAXTARGET_PERCENT_FOR_BIASED_RANDOMSEL        = 0xdf8203,
    PTAG_INTERAC_RETRY_COUNTER                         = 0xdf8204,
    ETAG_INTERAC_TERMINAL_CAPABILITIES                 = 0xdf8206,
    PTAG_VISA_CVN17_ENABLE                             = 0xdf8317,
    PTAG_VISA_TERM_ENTRY_CAPABILITY                    = 0xdf833c,
    PTAG_TRANSACTION_TYPE_BITMASK                      = 0xdf8511,
    PTAG_ENABLE_TLVDB_TAG_INDEXING                     = 0xdf8512,
    PTAG_EFTPOS_LEGACY_CARD_OUTCOME_DOL                = 0xdf8513,
    PTAG_EFTPOS_APP_SELECTION_SUPPORTED                = 0xdf8514,
    PTAG_LEAST_COST_ROUTING_LIMIT                      = 0xdf8515,
    PTAG_LEAST_COST_ROUTING_BINLIST                    = 0xdf8516,
    PTAG_LEAST_COST_ROUTING_8_DIGIT_BINLIST            = 0xdf8517,
    PTAG_CERTIFICATION_FEATURE                         = 0xdf8520,
    PTAG_CT_MAX_CARD_ERROR_COUNT                       = 0xdf8521,
    PTAG_APP_SELECTION_INDICATOR                       = 0xdf8525,
    PTAG_DE_CAP_INFO                                   = 0xdf8526,
    PTAG_ENTRYPOINT_CONFIG                             = 0xdf8530,
    PTAG_PREPROCESSING_CHECK_FLAG                      = 0xdf8532,
    PTAG_CL_TR_LIMIT                                   = 0xdf8533,
    PTAG_EMV_OUTCOME_DOL                               = 0xdf853d,
    PTAG_MSD_OUTCOME_DOL                               = 0xdf853e,
    PTAG_REVERSAL_OUTCOME_DOL                          = 0xdf853f,
    PTAG_ADVICE_OUTCOME_DOL                            = 0xdf8540,
    PTAG_AMEX_UN_RANGE                                 = 0xdf8541,
    PTAG_TRACK2_DATA                                   = 0xdf8542,
    PTAG_TRACK1_DATA                                   = 0xdf8543,
    PTAG_MAX_CARD_READ_RETRY                           = 0xdf854c,
    PTAG_EXCEPTION_FILE_HASH_DOL                       = 0xdf8554,
    PTAG_ISSUER_SCRIPT_RESULT                          = 0xdf8556,
    PTAG_TRANSACTION_AMOUNT                            = 0xdf855a,
    PTAG_TRANSACTION_FEATURE                           = 0xdf855c,
    PTAG_CL_PARTIAL_SELECT                             = 0xdf8563,
    PTAG_PIN_BYPASS_ENABLED                            = 0xdf8564,
    PTAG_MSD_NOCVN17_OUTCOME_DOL                       = 0xdf8565,
    PTAG_PIN_BYPASS_INTL_ONLY_ENABLED                  = 0xdf8567,
    PTAG_TRANSACTION_LIMIT_SET                         = 0xdf8568,
    PTAG_DRL_ACTIVE                                    = 0xdf856a,
    PTAG_CT_CVM_REQUIRED_LIMIT                         = 0xdf856c,
    PTAG_CT_CVM_CAP_BELOW_LIMIT                        = 0xdf856d,
    PTAG_CT_MCC_WHITELIST_FOR_CVM_CAP                  = 0xdf856e,
    PTAG_SPE_PAYMENT_FEATURE                           = 0xdf856f,
    PTAG_ENABLE_APPLICATION_SELECTION_FLAG             = 0xdf8574,
    PTAG_ENABLE_PSE_SELECTION                          = 0xdf8575,
    PTAG_COMMON_DEBIT_AID_LIST                         = 0xdf8576,
    PTAG_COMMON_DEBIT_ENABLED                          = 0xdf8577,
    PTAG_ENABLE_UNLOCK_PHONE                           = 0xdf8578,
    PTAG_MISC_CONFIGURATION                            = 0xdf857b,
    PTAG_SCHEME_FALLBACK_LIST                          = 0xdf857d,
    PTAG_ENABLE_GET_TRID                               = 0xdf857e,
    PTAG_ENABLE_SELECT_VAS                             = 0xdf857f,
    PTAG_SONIC_BRANDING                                = 0xdf8601,
    PTAG_ENABLE_PAN_MASKING                            = 0xdf8602,
    PTAG_COMMON_DEBIT_TYPE                             = 0xdf8603,
    PTAG_COMBINATION_OPTIONS                           = 0xdf8611,
    PTAG_TRANSACTION_MODE                              = 0xdf8612,
    PTAG_ISSUER_PIN_REQUEST                            = 0xdf8f01,
    PTAG_ISSUER_SCA_CODE                               = 0xdf8f02,
    ETAG_TAGS_TO_WRITE_BEFORE_GAC                      = 0xff8102,
    ETAG_TAGS_TO_WRITE_AFTER_GAC                       = 0xff8103,
    ETAG_DATA_RECORD                                   = 0xff8105,
    ETAG_TERMINAL_DD_DATA                              = 0xff8106,
    PTAG_VISA_IRWIN_READER_TERMINAL                    = 0xff8107,
    ETAG_ADVICE_RECORD                                 = 0xff8108,
    ETAG_REVERSAL_RECORD                               = 0xff8109,
    ETAG_EMV_FINANCIAL_REQ                             = 0xff810a,
    ETAG_EMV_FINANCIAL_CONF                            = 0xff810b,
    PTAG_TRANSACTION_RELATED_DEFAULT_DATA              = 0xff8512,
    PTAG_ADD_REVOCATION_LIST_ENTRY                     = 0xff8513,
    PTAG_MSG_SIGNAL_SET                                = 0xff854b,
    PTAG_OUT_SIGNAL                                    = 0xff8561,
    PTAG_SERVICE_DEBUG_DATA                            = 0xff810c,
    PTAG_COMMAND_ID                                    = 0xdf8528,
    PTAG_LAST_CARD_RESPONSE                            = 0xdf8529,
    ETAG_KEY_VERSION                                   = 0x85,
    ETAG_CA_PUBKEY_INDEX_READER                        = 0x9f22,
    ETAG_VAS_APPLICATION_VERSION_NUMBER_TERMINAL       = 0x9f22,
    ETAG_DRDOL                                         = 0x9f51,
    ETAG_DS_ODS_CARD                                   = 0x9f54,
    ETAG_CVC3_T1                                       = 0x9f60,
    ETAG_JCB_ISSUER_UPDATE_PARAMETER                   = 0x9f60,
    ETAG_CVC3_T2                                       = 0x9f61,
    ETAG_PCVC3_T1                                      = 0x9f62,
    ETAG_NATC_T1                                       = 0x9f64,
    ETAG_PCVC3_T2                                      = 0x9f65,
    ETAG_NATC_T2                                       = 0x9f67,
    ETAG_DS_SLOT_MANAGEMENT_CONTROL                    = 0x9f6f,
    ETAG_DS_UNPREDICTABLE_NUMBER                       = 0x9f7f,
    ETAG_POS_CH_INTERACTION_INFO                       = 0xdf4b,
    ETAG_DS_DIGEST_H                                   = 0xdf61,
    ETAG_DS_SUMMARY_2                                  = 0xdf8101,
    ETAG_DS_SUMMARY_3                                  = 0xdf8102,
    ETAG_DATA_NEEDED                                   = 0xdf8106,
    ETAG_CDOL1_RELATED_DATA                            = 0xdf8107,
    ETAG_DS_SUMMARY_STATUS                             = 0xdf810b,
    ETAG_DRDOL_RELATED_DATA                            = 0xdf8113,
    ETAG_REFERENCE_CONTROL_PARAM                       = 0xdf8114,
    ETAG_PDOL_RELATED_DATA                             = 0xdf8111,
    ETAG_TIME_OUT_VALUE                                = 0xdf8127,
    ETAG_DDCARD_T1                                     = 0xdf812a,
    ETAG_DDCARD_T2                                     = 0xdf812b,
    ETAG_PHONE_MSG_TABLE                               = 0xdf8131,
    ETAG_RRP_TIME_MISMATCH_THRESHOLD                   = 0xdf8137,
    ETAG_RRP_ENTROPY_TERMINAL                          = 0xdf8301,
    ETAG_RRP_ENTROPY_DEVICE                            = 0xdf8302,
    ETAG_RRP_APDU_MIN_TIME                             = 0xdf8303,
    ETAG_RRP_APDU_MAX_TIME                             = 0xdf8304,
    ETAG_RRP_APDU_DEVICE_ESTIMATED_TIME                = 0xdf8305,
    ETAG_RRP_TIME_MEASURED                             = 0xdf8306,
    ETAG_RRP_COUNTER                                   = 0xdf8307,
    ETAG_TORN_RECORD                                   = 0xff8101,
    ETAG_DATA_TO_SEND                                  = 0xff8104,
    ETAG_ICC_UID                                       = 0xdf8205,
    ETAG_DISCOVER_OFFLINE_BALANCE                      = 0xd1,
    PTAG_UIRESPONSE_CODE                               = 0xd1,
    PTAG_NDEF_REQUEST_TYPE                             = 0xd1,
    ETAG_IGNORE_KERNEL_IDENTIFIER                      = 0x9f28,
    ETAG_VAS_UNPREDICTABLE_NUMBER_TERMINAL             = 0x9f28,
    ETAG_VAS_MERCHANT_LOYALTY_URL                      = 0x9f29,
    ETAG_EXTENDED_SELECTION                            = 0x9f29,
    ETAG_KERNEL_IDENTIFIER                             = 0x9f2A,
    PTAG_VAS_MERCHANT_LOYALTY_ID_LIST                  = 0xdf8142,
    PTAG_SELECTED_COMBINATION                          = 0xdf8522,
    PTAG_STATUS_BYTES                                  = 0xdf8523,
    PTAG_READER_SUPPORTED_LIST                         = 0xdf8524,
    PTAG_TORN_TEMP_RECORD                              = 0xdf8527,
    PTAG_PREPROCESSING_INDICATOR                       = 0xdf8531,
    PTAG_PREPROCESSING_TTQ                             = 0xdf8534,
    PTAG_RSA_KEY_ALGO_INDICATOR                        = 0xdf8535,
    PTAG_HASH_ALGO_INDICATOR                           = 0xdf8536,
    PTAG_CRYPTO_RSA_RECOVER_INPUT                      = 0xdf8537,
    PTAG_TORN_RECORD                                   = 0xdf8538,
    PTAG_SELECTNEXT_OUTCOME_PARAM_SET                  = 0xff8539,
    PTAG_GPO_CMD_DATA                                  = 0xdf853a,
    PTAG_GAC1_CMD_DATA                                 = 0xdf853b,
    PTAG_GAC2_CMD_DATA                                 = 0xdf853c,
    PTAG_GENERATE_NEW_UN                               = 0xdf8544,
    PTAG_IS_RESTARTED                                  = 0xdf8545,
    PTAG_SUPPRESSION_CODE_OR_CONDITIONS                = 0xff8548,
    PTAG_SUPPRESSION_CODE_CONDITIONS                   = 0xdf8549,
    PTAG_TERMINAL_COUNTRY_CODE_ALPHA3                  = 0xdf854a,
    PTAG_END_APP_TRY_AGAIN_OUTCOME                     = 0xff854d,
    PTAG_ISSUER_PUB_KEY_PLAIN_CERT                     = 0xdf854e,
    PTAG_ICC_PUB_KEY_PLAIN_CERT                        = 0xdf854f,
    PTAG_PE_PUB_KEY_PLAIN_CERT                         = 0xdf8550,
    PTAG_SDAD_PLAIN_CERT                               = 0xdf8551,
    PTAG_SSAD_PLAIN_CERT                               = 0xdf8552,
    PTAG_TRANSACTION_LOG_FLAG                          = 0xdf8553,
    PTAG_MERCHANT_FORCED_ONLINE                        = 0xdf8557,
    PTAG_ISSURE_VOICE_REFERRAL                         = 0xdf8558,
    PTAG_ASK_ACCOUNT_TYPE                              = 0xdf8559,
    PTAG_PIN_INPUT                                     = 0xdf855b,
    PTAG_START_CONTACT_CARD_REMOVAL                    = 0xdf855e,
    PTAG_UI_STATUS                                     = 0xdf855f,
    PTAG_PARTIAL_EMV_TX                                = 0xdf8560,
    PTAG_CARDHOLDER_PREFERRED_LANGUAGE                 = 0xdf8562,
    PTAG_FIELDOFF_DELAY                                = 0xdf8569,
    PTAG_GPO_RESP_DATA                                 = 0xdf856b,
    PTAG_CRYPTO_INPUT_DATA                             = 0xdf8570,
    PTAG_CRYPTO_KEY_DATA                               = 0xdf8571,
    PTAG_CRYPTO_ICV_DATA                               = 0xdf8572,
    PTAG_ADDITIONAL_SDAD_DATA                          = 0xdf8573,
    PTAG_AMOUNT_OK_TIMEOUT                             = 0xdf8579,
    PTAG_SELECT_ACCOUNT_TIMEOUT                        = 0xdf857a,
    PTAG_MAX_ALLOWED_COLLISION_ERROR                   = 0xdf857c,
    PTAG_BUZZER_LED_DATA                               = 0xdf8604,
    PTAG_CARD_WAIT_TIMEOUT                             = 0xdf8605,
    PTAG_ADDITIONAL_SPE_PAYMENT_FEATURE                = 0xdf8606,
    PTAG_TAP_TO_PHONE_DEVICE                           = 0xdf8607,
    PTAG_TERM_TENDER_TYPE                              = 0xdf23,
    PTAG_UIREQUEST_LIST                                = 0xdf23,
    PTAG_TERM_ALLOWED_TRANSACTIONS                     = 0xdf24,
    PTAG_UIREQUEST_SELECTED_AID                        = 0xdf24,
    PTAG_PIN_PAD_TIMER_DIGITS                          = 0xdf25,
    PTAG_UIREQUEST_ACCOUNT_TYPE_LIST                   = 0xdf25,
    PTAG_PIN_PAD_TIMER                                 = 0xdf26,
    PTAG_UIREQUEST_AUDIO_VISUAL_ID                     = 0xdf26,
    PTAG_START_CARD_REMOVAL_ALERT_TONE                 = 0xdf29,
    PTAG_TRACK2_ENC_FLAG                               = 0xdf2a,
    PTAG_IS_CAHSBACK_AMT_PART_OF_AMT_AUTH              = 0xdf2b,
    PTAG_CURRENCY_SYMBOL_ASCII                         = 0xdf2d,
    PTAG_PUBKEY_MODULUS                                = 0xdf31,
    PTAG_STARTPAYREQ_TRANSACTION_MODE                  = 0xdf31,
    PTAG_PUBKEY_EXP                                    = 0xdf32,
    PTAG_PUBKEY_CHECKSUM                               = 0xdf33,
    PTAG_CA_PUBKEY_EXPIRY_DATE                         = 0xdf36,
    ETAG_DATA_STORAGE_DIRECTORY                        = 0xdf3d,
    ETAG_DATA_STORE                                    = 0xdf3f,
    PTAG_CANDIDATE_LIST_ENTRY                          = 0xe1,
    PTAG_AID_ENTRY                                     = 0xe1,
    PTAG_RID_ENTRY                                     = 0xe1,
    PTAG_PUBLICKEY_ENTRY                               = 0xe2,
    PTAG_REVOCATION_LIST_ENTRY                         = 0xe3,
    PTAG_CURRENCY_MAP_ENTRY                            = 0xe3,
    PTAG_VISA_TRACK1_INCLUDED                          = 0xdf831c,
    PTAG_VISA_TRACK2_INCLUDED                          = 0xdf832c,
    PTAG_UIMESSAGE_ACTORID                             = 0xd2,
    PTAG_NDEF_CARD_APP_VER                             = 0xd2,
    PTAG_UIRESPONSE_TOUCHPADKEY                        = 0xd3,
    PTAG_NDEF_MERCHANT_ID                              = 0xd3,
    PTAG_UIRESPONSE_INPUT                              = 0xd4,
    PTAG_NDEF_APPLICATION_TYPE                         = 0xd4,
    PTAG_UIRESPONSE_PINBYPASSED                        = 0xd5,
    PTAG_NDEF_CARD_ID                                  = 0xd5,
    PTAG_UIRESPONSE_LISTINDEX                          = 0xd6,
    PTAG_NDEF_CARD_TYPE                                = 0xd6,
    PTAG_UIRESPONSE_VOICEREFER                         = 0xd8,
    PTAG_NDEF_RESULT                                   = 0xd8,
    PTAG_DETRESPONSE_ID                                = 0xda,
    PTAG_NDEF_CARD_WAIT_TIMEOUT                        = 0xda,
    PTAG_DETRESPONSE_DATA                              = 0xdb,
    PTAG_DETRESPONSE_NEXT_DET_REQUIRED                 = 0xdc,
    PTAG_SIGNALRESPONSE_P1                             = 0xdd,
    PTAG_SIGNALRESPONSE_DATA                           = 0xde,
    PTAG_NDEF_APPLICATION_TEMPLATE                     = 0xe0,
    PTAG_NDEF_RESPONSE_TYPE                            = 0xd9,
    PTAG_DEKREQUEST_ID                                 = 0xdf01,
    PTAG_DEKREQUEST_DATA                               = 0xdf02,
    PTAG_DEKREQUEST_READY_TO_RECEIVE                   = 0xdf03,
    PTAG_UIREQUEST_USER_INTERFACE_TYPE                 = 0xdf10,
    PTAG_UIREQUEST_MSG_ID_COUNT                        = 0xdf11,
    PTAG_UIREQUEST_MSG_ID                              = 0xdf12,
    PTAG_UIREQUEST_TIMEOUT_MS                          = 0xdf13,
    PTAG_UIREQUEST_LANGUAGE_PREFERENCE                 = 0xdf14,
    PTAG_UIREQUEST_TERMINAL_DEFAULT_LANGUAGE           = 0xdf15,
    PTAG_UIREQUEST_TRANSACTION_TYPE                    = 0xdf16,
    PTAG_UIREQUEST_TRANSACTION_CURRENCY_CODE           = 0xdf17,
    PTAG_UIREQUEST_AMOUNT_AUTHORIZED                   = 0xdf18,
    PTAG_UIREQUEST_AMOUNT_AUTHORIZED_OTHER             = 0xdf19,
    PTAG_UIREQUEST_DIALOG_BOX                          = 0xdf1a,
    PTAG_UIREQUEST_INPUTTYPE                           = 0xdf1b,
    PTAG_UIREQUEST_KEY_TIMEOUT_MS                      = 0xdf1c,
    PTAG_UIREQUEST_MAX_DIGITS                          = 0xdf1d,
    PTAG_UIREQUEST_PERIOD_OFFSET                       = 0xdf1e,
    PTAG_UIREQUEST_PIN_BYPASS_ENABLED                  = 0xdf1f,
    PTAG_UIREQUEST_APP_LABEL                           = 0xdf20,
    PTAG_UIREQUEST_CURRENCY_EXPONENT                   = 0xdf28,
    PTAG_UIREQUEST_STATUS                              = 0xdf30,
    PTAG_VASRESPONSE_PROTOCOL                          = 0xdf40,
    PTAG_VASRESPONSE_RESULT                            = 0xdf41,
    PTAG_VASRESPONSE_DATA                              = 0xdf42,
    PTAG_VASRESPONSE_FINISHED                          = 0xdf43,
    PTAG_UIREQUEST_ISSUER_ID                           = 0xdf46,
    PTAG_UIREQUEST_PAN_LAST4                           = 0xdf47,
    PTAG_UIREQUEST_CH_NAME                             = 0xdf48,
    PTAG_UIREQUEST_PSEUDO_PAN                          = 0xdf49,
    PTAG_UIREQUEST_PANBLOCK                            = 0xdf4a,
    PTAG_UIREQUEST_ENCRYPT_PIN                         = 0xdf4c,
    PTAG_TXRS_APP_NOTIFY                               = 0xff8801,
    PTAG_TXRS_APP_NOTIFY_ICODE_TBL_IDX                 = 0xdf8801,
    PTAG_TXRS_APP_EXP_SEL_REQ                          = 0xdf8802,
    PTAG_TXRS_NOTIFICATION                             = 0xdf8803,
    PTAG_TXRS_POS_ENTRY_MODE                           = 0xdf8804,
    PTAG_TXRS_INTERCHANGE                              = 0xff8802,
    PTAG_TXRS_INTERCHANGE_TYPE                         = 0xdf8805,
    PTAG_TXRS_INTERCHANGE_ONLINE_PIN_PRESENT           = 0xdf8806,
    PTAG_TXRS_INTERCHANGE_PLAIN_TEXT_TLV               = 0xff8803,
    PTAG_TXRS_INTERCHANGE_ENCRYPTED_TLV                = 0xff8804,
    PTAG_TXRS_ERROR_LED_BUZZER_SEQ                     = 0xdf8807,
    PTAG_TXRS_FALLBACK                                 = 0xdf8808,
    PTAG_TXRS_RESULT                                   = 0xff8805,
    PTAG_TXRS_RESULT_CODE                              = 0xdf8809,
    PTAG_TXRS_RESULT_DISPOSITION                       = 0xdf880a,
    PTAG_TXRS_SIGNATURE_REQUESTED                      = 0xdf880b,
    PTAG_TXRS_RESULT_CARD_INFO                         = 0xff8806,
    PTAG_TXRS_RESULT_CARD_INFO_ISSUER_ID               = 0xdf880c,
    PTAG_TXRS_RESULT_CARD_INFO_LAST_FOUR               = 0xdf880d,
    PTAG_TXRS_PROFILE_SUPPORTED                        = 0xdf880e,
 } payment_tags_t;