
DROP TABLE IF EXISTS switchstatus;

CREATE TABLE switchstatus (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  status TEXT NOT NULL,
  identify TEXT NOT NULL
);
