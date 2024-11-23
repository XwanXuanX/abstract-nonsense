# remove all .bin files
# using "|| true" hack to ignore the return value of the previous command
.PHONY: clean
clean:
	@rm ./archive/*.bin   || true
	@rm -r ./archive/.cph || true
	@rm -r ./.vscode	  || true


# log information to terminal and to file
.PHONY: log
log:
	@python3 line-ave.py  || true


# add a new file to archive with a random name
GENERATE_NAME = $(shell openssl rand -base64 12 | sed 's/[^a-z0-9]//g')
SET_NAME = $(eval FILE_NAME=$(GENERATE_NAME))
FILE_PATH = ./archive/$(FILE_NAME).cpp
VSCODE_PATH = /Applications/"Visual Studio Code.app"/Contents/MacOS/Electron

.PHONY: file
file:
    # invoke this function to generate a new file name
	@$(SET_NAME)
	@touch $(FILE_PATH)
	@$(VSCODE_PATH) $(FILE_PATH)
	@echo "Successfully created and opened file: $(FILE_NAME).cpp"
	@echo "Starting timer...NOW!"
	@./watch.sh
