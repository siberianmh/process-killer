{
    'targets': [
        {
            'target_name': 'processKiller',
            'include_dirs': ['<!(node -e "require(\'nan\')")'],
            'conditions': [
                ['OS=="win"', {
                    'sources': [
                        'src/main.cc',
                    ],
                    'msvs_disabled_warnings': [
                        4267,
                        4530,
                        4506,
                    ]
                }]
            ]
        }
    ]
}
