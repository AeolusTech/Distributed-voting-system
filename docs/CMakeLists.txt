add_custom_target(plantuml_diagrams ALL
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/docs/
    COMMAND plantuml *.plantuml -tpng -o generated/
)