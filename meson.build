project('game', 'cpp')

src = [
    'src/main.cpp',
    'src/game_context.cpp',
    'src/sdl_context.cpp',
    'src/component.cpp',
    'src/entity.cpp'
]

incdirs = ['headers']

deps = [
    dependency('SDL3'),
    dependency('SDL3_image')
]

executable(
    'game', 
    src, 
    include_directories : incdirs, 
    dependencies : deps
)