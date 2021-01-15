const nativeModule =
  process.platform === 'win32'
    ? require('../build/Release/processKiller.node')
    : null

export const killProcessByName = (process: string) =>
  nativeModule.killProcessByName(process)
