CREATE TABLE tc_notifications (
  id SERIAL PRIMARY KEY,
  type VARCHAR(128) NOT NULL,
  attributes TEXT DEFAULT NULL,
  always BOOLEAN NOT NULL DEFAULT FALSE,
  calendarid INTEGER,
  notificators VARCHAR(128),
  commandid INTEGER,
  description TEXT
);

CREATE TABLE tc_device_notification (
  deviceid INTEGER NOT NULL,
  notificationid INTEGER NOT NULL,
  FOREIGN KEY (notificationid) REFERENCES tc_notifications(id)
);

CREATE TABLE tc_group_notification (
  groupid INTEGER NOT NULL,
  notificationid INTEGER NOT NULL,
  FOREIGN KEY (notificationid) REFERENCES tc_notifications(id)
);

CREATE TABLE tc_user_notification (
  userid INTEGER NOT NULL,
  notificationid INTEGER NOT NULL,
  FOREIGN KEY (notificationid) REFERENCES tc_notifications(id)
);

INSERT INTO tc_notifications (id, type, attributes, always, calendarid, notificators, commandid, description) VALUES
(32, 'commandResult', '{}', true, NULL, 'web', NULL, 'Modificada Ariel Nuevaso edit'),
(33, 'commandResult', '{}', false, NULL, 'web', NULL, 'Modificada Ariel Nuevaso edit'),
(37, 'deviceOnline', '{}', false, NULL, 'web', NULL, NULL),
(39, 'deviceOnline', '{}', true, NULL, 'web', NULL, 'Guradadaso desde el front'),
(40, 'deviceInactive', '{}', true, NULL, 'web,mail', NULL, 'Front purasoooo mas api'),
(41, 'deviceOnline', '{}', true, NULL, 'web', NULL, 'Diego1'),
(42, 'commandResult', '{}', true, NULL, 'command', 4, 'Actualizado'),
(43, 'deviceOnline', '{}', true, NULL, 'web', NULL, 'Actualizadon Cookie'),
(44, 'commandResult', '{}', true, 1, 'mail', NULL, 'adad'),
(45, 'deviceOnline', '{}', true, NULL, 'web,mail', NULL, 'Notificación de prueba Nuevo Ariel'),
(46, 'commandResult', '{}', true, 1, 'mail', NULL, 'ett'),
(47, 'commandResult', '{}', false, NULL, 'mail', NULL, NULL);

INSERT INTO tc_group_notification (groupid, notificationid) VALUES
(1, 43);

INSERT INTO tc_user_notification (userid, notificationid) VALUES
(2, 39),
(2, 40),
(2, 41),
(2, 42),
(2, 43);
