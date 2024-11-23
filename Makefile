# remove all .bin files
# using "|| true" hack to ignore the return value of the previous command
clean:
	rm ./archive/*.bin   || true
	rm -r ./archive/.cph || true
	rm -r ./.vscode	  	 || true
