remake_include(../connection ../serialization/types ../exceptions)
remake_add_library(ant PREFIX off LINK connection exceptions serialization)
remake_add_headers()
