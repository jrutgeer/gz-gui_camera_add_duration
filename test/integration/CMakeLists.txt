gz_get_sources(tests)

gz_build_tests(
  TYPE INTEGRATION
  SOURCES ${tests}
  LIB_DEPS
    ${PROJECT_NAME}_test_helpers
    gz-plugin${GZ_PLUGIN_VER}::loader
    gz-rendering${GZ_RENDERING_VER}::gz-rendering${GZ_RENDERING_VER}
    Qt::Test
)
