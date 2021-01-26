const path = require('path')
const { spawnSync } = require('child_process')

spawnSync(
  path.join(
    __dirname,
    '../node_modules/.bin/prebuild' +
      (process.platform === 'win32' ? '.cmd' : ''),
  ),
  ['--upload-all', process.env.GITHUB_TOKEN || process.env.GH_TOKEN],
  { stdio: 'inherit' },
)
