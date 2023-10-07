# Universal-Agent

The Universal Agent is a versatile cross-platform resource management tool designed for on-premise deployments. It provides comprehensive monitoring and management capabilities for various system resources.

## Features

- **Cross-Platform Compatibility:** Works seamlessly on Windows, Linux, and macOS systems.
- **Resource Monitoring:** Monitors CPU usage, memory usage, disk space, and more.
- **Curl Integration:** Includes a flexible Curl downloader for handling file downloads.
- **Easy Deployment:** Can be easily deployed on-premise using automation tools like Jenkins, Ansible, and Puppet.

## Deployment (On-Premise)

### Prerequisites

- **Supported Platforms:** Windows, Linux, macOS
- **Dependencies:** Ensure that Curl and necessary libraries are installed on the target systems.

### Deployment Steps

1. **Clone Repository:**
   ```bash
   git clone <repository-url>
   cd Universal-Agent
Build the Project:

For Linux/macOS:
bash
Copy code
make
For Windows, use a suitable build tool like Visual Studio or MinGW.
Configure Deployment:

Modify configuration files according to your deployment needs.
Update the config.json file with relevant settings.
Deploy Using Automation Tools:

Use Jenkins, Ansible, or Puppet to automate the deployment process.
Refer to automation scripts and playbooks provided in the automation/ directory.
Start the Universal Agent:

Execute the built executable or script to start the Universal Agent.
Ensure the agent is running and monitoring the specified resources.
Usage
Resource Monitoring:

Access the monitoring dashboard via the provided web interface.
Monitor CPU, memory, and disk usage in real-time.
File Download:

Utilize the Curl downloader for efficient and reliable file downloads.
Example: ./download.sh <file-url>
Contributing
Feel free to contribute to the development of the Universal Agent by creating issues or submitting pull requests.
