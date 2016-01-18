FIND_PACKAGE(Sphinx REQUIRED)

# HTML output directory
SET(SPHINX_HTML_DIR "${CMAKE_BINARY_DIR}/docs/html")


ADD_CUSTOM_TARGET(docs ALL sphinx-build -b html 
                        "${CMAKE_SOURCE_DIR}/docs/" 
                        "${SPHINX_HTML_DIR}")

# Building using 'make_docs.py' python script
#ADD_CUSTOM_TARGET(docs ALL
#                  python
#                  "${CMAKE_SOURCE_DIR}/scripts/make_docs.py"
#                  "${CMAKE_SOURCE_DIR}"
#                  "${CMAKE_BINARY_DIR}/docs"
#                  "${SPHINX_EXECUTABLE}"
#                  COMMENT "Building HTML documentation with Sphinx")
