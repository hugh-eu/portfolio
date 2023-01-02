package com.hugh.tripist.util;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;
import java.util.Vector;

import com.jcraft.jsch.Channel;
import com.jcraft.jsch.ChannelSftp;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.JSchException;
import com.jcraft.jsch.Session;
import com.jcraft.jsch.SftpException;

public class SCPUtil {
	private Session session;
	private Channel channel;
	private ChannelSftp channelSftp;
	private boolean inVaild = false;

	public void init(String serverIp, String serverId, String serverPw) {
		JSch jsch = new JSch();
		
		try {
	        session = jsch.getSession(serverId, serverIp, 22);
	        session.setPassword(serverPw);

	        Properties config = new Properties();
	        config.put("StrictHostKeyChecking", "no");
	        session.setConfig(config);
	        
	        session.connect();
	        
	        channel = session.openChannel("sftp");
	        channel.connect();
	        
	        channelSftp = (ChannelSftp) channel;
	        inVaild = true;
	        
		} catch (JSchException e) {
			e.printStackTrace();
			
		}
	}

	@SuppressWarnings("unchecked")
	public Vector<ChannelSftp.LsEntry> getFileList(String path) {
		Vector<ChannelSftp.LsEntry> list = null;
		
		try {
			channelSftp.cd(path);
			list = channelSftp.ls(".");
			
		} catch (Exception e) {
			e.printStackTrace();
			
		}
		
		return list;
		
	}
	
    public void upload(String path, File file) {
        FileInputStream in = null;
        
        try {
            in = new FileInputStream(file);
            channelSftp.cd(path);
            channelSftp.put(in, file.getName());
            
        } catch (SftpException e) {
            e.printStackTrace();
            
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            
        } finally {
            try {
            	if(in != null)
            		in.close();
            	
            } catch (IOException e) {
                e.printStackTrace();
                
            }
        }
    }

    public void download(String path, String fileName, String userPath) {
        InputStream in = null;
        FileOutputStream out = null;
        
        try {
            channelSftp.cd(path);
            in = channelSftp.get(fileName);
            
        } catch (SftpException e) {
            e.printStackTrace();
            
        }

        try {
        	String fullpath = userPath + File.separator + fileName;
            out = new FileOutputStream(new File(fullpath));
            int i;

            while ((i = in.read()) != -1) {
                out.write(i);
                
            }
        } catch (IOException e) {
            e.printStackTrace();
            
        } finally {
            try {
                out.close();
                in.close();
                
            } catch (IOException e) {
                e.printStackTrace();
                
            }

        }
    }

    public void disconnection() {
        channelSftp.quit();
        channel.disconnect();
        session.disconnect();
        setInVaild(false);
        
    }
    
	public boolean isInVaild() {
		
		return inVaild;
		
	}

	public void setInVaild(boolean inVaild) {
		this.inVaild = inVaild;
		
	}
}
