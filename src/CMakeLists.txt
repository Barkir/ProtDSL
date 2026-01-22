cmake_minimum_required(VERSION 3.10)
project(ricsv_decode VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BUILD_TYPE Debug)

# Исходные файлы
set(SOURCES
    main.cpp
)

set(HEADERS
    main.hpp
    decoders.hpp
    executers.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        # -Werror
	    -Weffc++
        -Waggressive-loop-optimizations
        -Wc++14-compat
        -Wmissing-declarations
        -Wcast-align -Wcast-qual
        -Wchar-subscripts
        -Wconditionally-supported
        -Wconversion
        -Wctor-dtor-privacy
        -Wempty-body -Wfloat-equal
        -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2
        -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd
        -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self
        -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo
        -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn
        -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override
        -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code
        -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix
        -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast
        -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation
        -fstack-protector -fstrict-overflow -flto-odr-type-merging
        -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE
        -Werror=vla
        # -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,
        # leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,
        # signed-integer-overflow,undefined,unreachable,vla-bound,vptr
    )
endif()

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
        /WX
    )
endif()
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
