;var AppLogBridge = {};

/* callback Memo */
AppLogBridge.callbackMemo = {
  backStore: {},
  setCallback: function (callback_id, callback) {
    this.backStore[callback_id] = callback;
  },
  getCallback: function (callback_id) {
    return this.backStore[callback_id];
  },
  removeCallback: function (callback_id) {
    delete this.backStore[callback_id];
  }
};

AppLogBridge.uuidv4 = function () {
  return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
    var r = Math.random() * 16 | 0, v = c == 'x' ? r : (r & 0x3 | 0x8);
    return v.toString(16);
  });
}

/* Bridged methods */
AppLogBridge.hasStarted = function (callback) {
  let callback_id = AppLogBridge.uuidv4();
  AppLogBridge.callbackMemo.setCallback(callback_id, callback);
  let message = {
    'method': 'hasStarted',
    'params': [],
    'callback_id': callback_id
  };
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.getDeviceId = function (callback) {
  let callback_id = AppLogBridge.uuidv4();
  AppLogBridge.callbackMemo.setCallback(callback_id, callback);

  let message = {
    'method': 'getDeviceId',
    'params': [],
    'callback_id': callback_id
  };
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.getIid = function (callback) {
  let callback_id = AppLogBridge.uuidv4();
  AppLogBridge.callbackMemo.setCallback(callback_id, callback);

  let message = {
    'method': 'getIid',
    'params': [],
    'callback_id': callback_id
  };
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.getSsid = function (callback) {
  let callback_id = AppLogBridge.uuidv4();
  AppLogBridge.callbackMemo.setCallback(callback_id, callback);

  let message = {
    'method': 'getSsid',
    'params': [],
    'callback_id': callback_id
  };
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.onEventV3 = function (event, paramsJSON) {
  let message = {
    'method': 'onEventV3',
    'params': [event, paramsJSON],
    'callback_id': null
  };
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
}

AppLogBridge.getUserUniqueId = function (callback) {
  let callback_id = AppLogBridge.uuidv4();
  AppLogBridge.callbackMemo.setCallback(callback_id, callback);

  let message = {
    'method': 'getUserUniqueId',
    'params': [],
    'callback_id': callback_id
  };
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.setUserUniqueId = function (userUniqueId) {
  let message = {
    'method': 'setUserUniqueId',
    'params': [userUniqueId],
    'callback_id': null
  }
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.profileSet = function (ObjJSON) {
  let message = {
    'method': 'profileSet',
    'params': [ObjJSON],
    'callback_id': null
  }
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.profileSetOnce = function (ObjJSON) {
  let message = {
    'method': 'profileSetOnce',
    'params': [ObjJSON],
    'callback_id': null
  }
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.profileIncrement = function (ObjJSON) {
  let message = {
    'method': 'profileIncrement',
    'params': [ObjJSON],
    'callback_id': null
  }
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.profileAppend = function (ObjJSON) {
  let message = {
    'method': 'profileAppend',
    'params': [ObjJSON],
    'callback_id': null
  }
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.profileUnset = function (unsetKey) {
  let message = {
    'method': 'profileUnset',
    'params': [unsetKey],
    'callback_id': null
  }
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.addHeaderInfo = function (key, value) {
  let message = {
    'method': 'addHeaderInfo',
    'params': [key, value],
    'callback_id': null
  }
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.removeHeaderInfo = function (headerKey) {
  let message = {
    'method': 'removeHeaderInfo',
    'params': [headerKey],
    'callback_id': null
  }
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.getABTestConfigValueForKey = function (key, defaultValue, callback) {
  let callback_id = AppLogBridge.uuidv4();
  AppLogBridge.callbackMemo.setCallback(callback_id, callback);

  let message = {
    'method': 'getABTestConfigValueForKey',
    'params': [key, defaultValue],
    'callback_id': callback_id
  };
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.getAbSdkVersion = function (callback) {
  let callback_id = AppLogBridge.uuidv4();
  AppLogBridge.callbackMemo.setCallback(callback_id, callback);

  let message = {
    'method': 'getAbSdkVersion',
    'params': [],
    'callback_id': callback_id
  };
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
}

AppLogBridge.setNativeAppId = function (appId) {
  let message = {
    'method': 'setNativeAppId',
    'params': [appId],
    'callback_id': null
  }
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};

AppLogBridge.setExternalAbVersion = function (vids) {
  let message = {
    'method': 'setExternalAbVersion',
    'params': [vids],
    'callback_id': null
  }
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
};


AppLogBridge.getAllAbTestConfigs = function (callback) {
  let callback_id = AppLogBridge.uuidv4();
  AppLogBridge.callbackMemo.setCallback(callback_id, callback);

  let message = {
    'method': 'getAllAbTestConfigs',
    'params': [],
    'callback_id': callback_id
  };
  window.webkit.messageHandlers.rangersapplog_ios_h5bridge_message_handler.postMessage(message);
}
