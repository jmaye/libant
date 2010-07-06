remake_include(../connection ../serialization/types ../exceptions)
remake_add_library(platform LINK connection exceptions)
remake_add_headers(INSTALL platform)
