import os
import time
import datetime
import pymysql
import paramiko
from scp import SCPClient, SCPException

DB_HOST = "192.168.0.101"
DB_USER = "hugh"
DB_PW = "1234"
DB_NAME = "db_detector"

class SSHManager:
    def __init__(self):
        self.ssh_client = None

    def create_ssh_client(self, hostname, username, password):
        if self.ssh_client is None:
            self.ssh_client = paramiko.SSHClient()
            self.ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
            self.ssh_client.connect(hostname, username=username, password=password)
        else:
            print("SSH client session exist.")

    def close_ssh_client(self):
        self.ssh_client.close()

    def send_file(self, local_path, remote_path):
        try:
            with SCPClient(self.ssh_client.get_transport()) as scp:
                scp.put(local_path, remote_path, preserve_times=True)
        except SCPException:
            raise SCPException.message

    def get_file(self, remote_path, local_path):
        try:
            with SCPClient(self.ssh_client.get_transport()) as scp:
                scp.get(remote_path, local_path)
        except SCPException:
            raise SCPException.message

    def send_command(self, command):
        stdin, stdout, stderr = self.ssh_client.exec_command(command)
        return stdout.readlines()

def insertImgInfo():
    imgs = os.listdir("imgs_detector/")
    imgs.sort()
    if len(imgs) > 0:
        conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
        cur = conn.cursor(pymysql.cursors.DictCursor)
        ssh_manager = SSHManager()
        ssh_manager.create_ssh_client("192.168.0.200", "hugh", "1234")
        for img in imgs:
            sql = "INSERT INTO tbl_imgs (i_img_name, i_reg_date) VALUES ('" + img + "', NOW())"
            cur.execute(sql)
            conn.commit()
            ssh_manager.send_file("imgs_detector/" + img, "/home/hugh/imgs_detector/" + img)
            os.remove("imgs_detector/" + img)
            print(f"[{datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}] {img} -- Just detected.")
        conn.close()
        ssh_manager.close_ssh_client()

if __name__ == "__main__":
    while True:
        insertImgInfo()
        time.sleep(0.1)
