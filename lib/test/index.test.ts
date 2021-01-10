import { killProcessByName } from '..'
import * as execa from 'execa'

describe('processKiller', () => {
  beforeEach(() => {
    // ensure notepad doesn't laucnhed
    killProcessByName('notepad.exe')
  })

  test('closes processes', async () => {
    await execa('powershell.exe', ['Start-Process', 'notepad.exe'])
    const result = killProcessByName('notepad.exe')
    expect(result).toBe(true)
  })

  test('return false if process not runned', () => {
    const result = killProcessByName('notepad.exe')
    expect(result).toBe(false)
  })
})
