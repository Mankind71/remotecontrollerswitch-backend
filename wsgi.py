from main import app, d
import sys, os

if __name__ == "__main__":
    if os.path.exists("remotecontrolled.db"):
        os.remove("remotecontrolled.db")
    if os.path.exists("remotecontrolled.db.overflow"):
        os.remove("remotecontrolled.db.overflow")
    try:
        app.run()
    except Exception:
        pass
    finally:
        d.Close()
