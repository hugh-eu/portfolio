import os
import time
import datetime
import pymysql
import paramiko
from scp import SCPClient, SCPException

LOCAL_PATH = "/home/hugh/detector/img/"
REMOTE_PATH = "/home/hugh/imgs_detector/"
DEVICE = "cam01248523"

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

def app():
    while True:
        imgs = sorted(os.listdir(LOCAL_PATH))
        if len(imgs) > 0:
            ssh_manager = SSHManager()
            ssh_manager.create_ssh_client("192.168.0.103", "hugh", "1234")
            conn = pymysql.connect(user="hugh", passwd="1234", host="192.168.0.101", db="db_detector", charset="utf8")
            cur = conn.cursor()
            for img in imgs:
                ssh_manager.send_file(LOCAL_PATH + img, REMOTE_PATH + img)
                sql = "INSERT INTO tbl_imgs (i_device, i_img_name, i_reg_date) VALUES ('" + DEVICE + "', '" + img + "', NOW())"
                cur.execute(sql)
                os.remove(LOCAL_PATH + img)
                print(LOCAL_PATH + img + "-----> Just detected.", datetime.datetime.now().strftime("[%Y-%m-%d %H:%M:%S]"))
            ssh_manager.close_ssh_client()
            conn.commit()
            conn.close()
        time.sleep(0.5)


if __name__ == "__main__":
    app()