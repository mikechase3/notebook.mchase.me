# How to setup Ollama and WebUI

I went to Microcenter and bought 128gb of RAM for this because it's my job to figure this out. I'm in charge of some sort-of experiment where I have to make the LLMs bend to my will by challenging them with deterrence like problems found in economics like the ultimatum game, the dictator game, etc.

This is going to be a casual log of stuff that I'd love to clean up later if I have the time and willpower to, but I'll unfortunately be moving onto bigger and better things because I've got work to do and people want features and not great documentation. And so, this'll only be understood by myself until I do it a second time and clean up my lost hamlet monologues.

The larger narrative here is that I specialized in game engines and digital twin work, but now I'm learning about AI, LLMs, etc which is great because it's the cutting-edge stuff as of when I'm writing it. Chat GPT came out and the NVIDIA basically specialized in the GPUs that do it most efficiently and we're building tons of data centers amongst other geopolitical issues going on.

So what did I do so far. Unfortunately, I did half of it before I decided to document it. Let's see..  So far I basically figured out how to use Docker because that's a newish skill for me. I made a project folder where I keep my projects and named it after one of my coworkers who had the idea.

Also, I'm doing this with Docker, but really you should use Podman because it's open source and Docker Desktop charges us for licensing using your tax dollars. It's free for personal use in your home labs and since I don't know what I'm doing, I'm going to start with this as it's better documented & more widely used.

Bad code:

So the command I'm seeing says run `docker run -d --name ollama --restart always -p 11434:11434 --gpus all -v ollama/:root/.ollama ollama/ollama`&#x20;

Now I should understand what that all means as I'm running into an error already. The error ain't important but here's what we tried to do. I think this might've worked better on Ubuntu but I've got a windows machine at the moment. And my linux dedicated server is a 2012 mac mini. I think mine has a dual core processor in it, which was alright at the time. Quad cores and hex cores just started to become used in consumer electronics at the time I bought it with that $600 I worked so hard to save up after my parents took my iPod touch because I was too young for it.

<figure><img src="../../../../../.gitbook/assets/image (818).png" alt=""><figcaption></figcaption></figure>

So...&#x20;

```bash
docker run 
    -d # daemon mode.
    --name ollama  # Name of the new CONTAINER
    --restart always # Start it when it stops.
    -p 11434:11434  # Map port on your PC to the port on the container.
    --gpus all  # Give the container access to NVDIA GPUs
    -v "D:\Purgable\GDrive\Projects\Daniel":/root/.ollama
    ollama/ollama
```

Nope.

PS D:\Purgable\DockerServer\OllamaLLM> docker run -d --name ollama --restart always -p 11434:11434 --gpus all -v "D:\Purgable\DockerServer\OllamaLLM":/root/.ollama ollama/ollama\
docker: invalid reference format

## Solution

Make a docker-compose.yml file in an empty folder/project.

```yaml
# This file defines your entire AI chat setup.
# Docker Compose will read this and create everything needed.
version: '3.8'

services:
  # The Ollama service that runs the language models
  ollama:
    image: ollama/ollama
    container_name: ollama
    # This creates a folder named 'ollama-data' next to your yml file
    # to permanently store the downloaded models.
    volumes:
      - ./ollama-data:/root/.ollama
    ports:
      - "11434:11434"
    # This section is for using an NVIDIA GPU. If you don't have one,
    # you can safely delete the 'deploy:' section.
    deploy:
      resources:
        reservations:
          devices:
            - driver: nvidia
              count: all
              capabilities: [gpu]
    restart: unless-stopped

  # The OpenWebUI service that gives you a chat interface
  webui:
    image: ghcr.io/open-webui/open-webui:main
    container_name: open-webui
    ports:
      - "3000:8080" # Access the UI on http://localhost:3000
    # This tells the Web UI how to find the Ollama service.
    environment:
      - OLLAMA_BASE_URL=http://ollama:11434
    # This creates 'webui-data' to store chat history and user settings.
    volumes:
      - ./webui-data:/app/backend/data
    # This ensures Ollama starts up first before the Web UI tries to connect.
    depends_on:
      - ollama
    restart: unless-stopped
```

This worked for me. With a warning about the code that was somewhat AI generated...

<figure><img src="../../../../../.gitbook/assets/image (820).png" alt=""><figcaption></figcaption></figure>



Welp. It started but I couldn't get a response from my browser so that's odd. Is it booting up still maybe? I did only give it about 10 seconds... Oh yeah, look at that it works if you give it ten seconds because you remember it's actually booting a little linux machine without the kernel parts and putting together a bunch of packages and WebUI was 2GB wtf is in it a whole copy of node? Probably honestly. No wonder why I don't love the web anymore; I think it's slow unless you're on a power PC which most people aren't.



<figure><img src="../../../../../.gitbook/assets/image (821).png" alt=""><figcaption></figcaption></figure>

I gave it my `protectmikechase` email, my dev password, and not my full name.

## .

Hi
