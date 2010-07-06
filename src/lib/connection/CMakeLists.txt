remake_include(../serialization ../serialization/types ../exceptions)
remake_add_library(connection LINK serialization exceptions)
remake_add_headers(INSTALL connection)
