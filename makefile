
all release debug clean rebuild:
	$(MAKE) -C common $@
	$(MAKE) -C utility $@
	$(MAKE) -C yk_db_service_impl $@
