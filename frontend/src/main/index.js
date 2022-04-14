const { app, BrowserWindow, dialog, ipcMain } = require('electron');
const path = require('path');
const child_process = require('child_process');
const getPortSync = require('get-port-sync');

let freePort = null;

try {
  freePort = getPortSync();
  console.log(freePort);
} catch (e) {
  console.log(e);
}
var executablePath;
var loader;

if (process.platform == 'win32')
  executablePath = path.join(__dirname, '../../lib/app.exe');
else {
  executablePath = path.join(__dirname, '../../lib/app');
}

// Handle creating/removing shortcuts on Windows when installing/uninstalling.
if (require('electron-squirrel-startup')) { // eslint-disable-line global-require
  app.quit();
}

process.on('loaded', (event, args) => {
  console.log('LOADED');
  console.log(app.getAppPath());

  // Start Backend Server
  loader = child_process.spawn(executablePath, [`--app_root=${app.getAppPath()}`, `--port=${freePort}`], { detached: true });
});

app.on('before-quit', function () {
  console.log("Quiting");
  process.kill(loader.pid);
});

ipcMain.handle('ipc-getPort', async (event, arg) => {
  return freePort;
});

ipcMain.handle('ipc-Dialog', async (event, arg) => {
  let properties = ['openFile', 'multiSelections'];
  let filters = [];
  console.log(arg);
  if (arg.type === "Dir") {
    properties = ["openDirectory"];
  }
  if (arg.type === "Single") {
    properties = ["openFile"];
  }

  if (arg.filter === "csv") {
    filters.push({
      "name": "csv file",
      "extensions": ["csv"]
    });
  }
  if (arg.filter === "raws") {
    filters.push({
      "name": "raw & tiff file",
      "extensions": ["cr2", "raf", "nef", "arq", "arw", "tiff", "tif"]
    });
  }
  if (arg.filter === "project") {
    filters.push({
      "name": "BeyondRGB project file",
      "extensions": ["btrgb"]
    });
  }


  const dia = await dialog.showOpenDialog({
    properties,
    filters
  }).then(result => {
    return result;
  }).catch(err => {
    console.log(err);
  });
  return dia;
});

// process.on('loaded', (event, args) => {
//   console.log('LOADED');
//   console.log(process.resourcesPath);
//   // console.log(process.getCPUUsage());
//   // console.log(process.getProcessMemoryInfo());
//   console.log(app.getAppPath());
// });

const createWindow = () => {
  // Create the browser window.
  const mainWindow = new BrowserWindow({
    width: 1100,
    height: 650,
    autoHideMenuBar: true,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'),
    },
  });

  // and load the index.html of the app.
  if (process.env.ELEC_ENV === 'dev') {
    mainWindow.loadURL('http://localhost:3000');
    // Open the DevTools.
    mainWindow.webContents.openDevTools();
  } else {
    mainWindow.loadFile(path.join(__dirname, '../../public/index.html'));
    // mainWindow.loadURL(`file://${path.join(__dirname, '../../public/index.html')}`);
  }

};

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.on('ready', createWindow);

// Quit when all windows are closed, except on macOS. There, it's common
// for applications and their menu bar to stay active until the user quits
// explicitly with Cmd + Q.
app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});

app.on('activate', () => {
  // On OS X it's common to re-create a window in the app when the
  // dock icon is clicked and there are no other windows open.
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow();
  }
});

// In this file you can include the rest of your app's specific main process
// code. You can also put them in separate files and import them here.
