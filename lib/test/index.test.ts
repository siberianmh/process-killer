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
    expect(result).toBeNull()
  })

  test('return error if process cannot be stopped', () => {
    expect(() => {
      killProcessByName('notepad.exe')
    }).toThrowError('Unexpected error while stopping the process.')
  })
})
